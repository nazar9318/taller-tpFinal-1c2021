#include "Match.h"
#include <string>

#define MAX_ITERATIONS 15

// POST: Crea una partida con el tipo de mapa correspondiente
//       y agrega al jugador a la misma.
Match::Match(Socket& socket, const std::string& map_type,
			const std::string& player_name): match_started(false),
			finished(false), last_id(0),
			game_world(map_type), handler(game_world),
			statistics_not_sent(true), init_players_not_sent(true),
			final_state_not_send(true) {
	game_world.add_player_if_not_full(last_id);
	Player* player = new Player(socket, last_id, player_name, to_process_events, true);
	if (!player)
		throw Exception("No se pudo alocar memoria para el jugador");
	players[last_id] = player;
	last_id++;
	syslog(LOG_INFO, "[%s:%i]: Se crea el match con mapa %s"
					 , __FILE__, __LINE__, map_type.c_str());
}


// PRE: La partida no comenzo y tiene lugar para un jugador mas.
// POST: Une a la partida al jugador.
void Match::join_player_if_not_full(Socket& skt,
						const std::string& player_name) {
	std::lock_guard<std::mutex> l(m);
	if (match_started) {
		throw ExceptionInvalidCommand("El juego ya comenzo",
		 	ServerError::MATCH_ALREADY_STARTED);
	}
	game_world.add_player_if_not_full(last_id);
	Player* player = new Player(skt, last_id, player_name, to_process_events);
	if (!player) {
		game_world.delete_player(last_id);
		throw Exception("No se pudo alocar memoria");
	}
	players[last_id] = player;
	std::shared_ptr<Event> players_info(new SendPlayersIdsEvent(players));
	for (auto it = players.begin(); it != players.end(); ++it) {
			std::shared_ptr<Event> to_push = players_info;
			it->second->push(to_push);
	}
	last_id++;
}

bool Match::is_finished() {
	return finished;
}


// Descripcion: Comienza la partida una vez que se lee el mensaje
//              correspondiente mediante el protocolo. Implementa
//              el game-loop.
void Match::run() {
	try {
		start_game();
		syslog(LOG_INFO, "[%s:%i]: Termina la etapa de start"
						, __FILE__, __LINE__);
		game_loop();
	} catch(std::exception& e) {
		syslog(LOG_CRIT, "[%s:%i]: %s", __FILE__, __LINE__, e.what());
	} catch (...) {
		syslog(LOG_CRIT, "[%s:%i]: Unknown Error", __FILE__, __LINE__);
	}
	finished = true;
}


void Match::start_game() {
	while(!match_started && !finished) {
		Event event = to_process_events.blocking_pop();
		// bloqueamos para no aceptar mas jugadores.
		while (event.get_type() == ClientTypeEvent::PLAYER_ABANDONS) {
			game_world.delete_player(event.get_id());
			event = to_process_events.blocking_pop();
		}
		std::lock_guard<std::mutex> l(m);
		match_started = true;
		StartGameHandler game_starter;
		try {
			game_starter.handle(event, players, game_world);
		} catch(ExceptionInvalidCommand& e) {
			std::shared_ptr<Event> error(new ErrorEvent(e.get_type()));
			for (auto it = players.begin(); it != players.end(); ++it) {
				std::shared_ptr<Event> to_push = error;
				it->second->push(to_push);
			}
			if (e.get_type() == ServerError::CREATOR_ABANDONS_MATCH) {
				finished = true;
			} else {
				match_started = false;
			}
		}
	}
}

bool Match::has_started() {
	return match_started;
}

void Match::game_loop() {
	using namespace std::chrono;
	auto begin = steady_clock::now();
	auto end = steady_clock::now();
	double t_delta;

	while (!finished) {
		begin = steady_clock::now();
		handle_events();
		finished = !game_world.simulate_step();
		push_step_events();
		end = steady_clock::now();
		t_delta = duration<double>(end - begin).count();
		if (t_delta < STEP_TIME)
			std::this_thread::sleep_for(duration<double>(STEP_TIME - t_delta));
	}
}

// POST: Desencola los eventos recibidos por los clientes y los
//       maneja.
void Match::handle_events() {
	bool queue_not_empty = true;
	int i = 0;
	while (queue_not_empty && MAX_ITERATIONS > i) {
		try {
			Event event = to_process_events.pop();
			handler.handle(event);
			i++;
		} catch(ExceptionEmptyQueue& e) {
			queue_not_empty = false;
		}
	}
}


// POST: Envia todos los eventos que sucedieron en el ultimo step
//       dependiendo de la fase actual.
void Match::push_step_events() {
	if (game_world.get_fase() == FaseType::INITIAL_FASE) {
		std::shared_ptr<Event> init_event(
			new SendStepInitEvent(game_world.get_step_info()));
		push_event(init_event);
		if (game_world.get_step_info().any_buys()) {
			std::shared_ptr<Event> buys(
				new SendBuysEvent(game_world.get_step_info()));
			push_event(buys);
			syslog(LOG_INFO, "[%s:%i]: Mando buys "
				 , __FILE__, __LINE__);
		}
		if (init_players_not_sent) {
			std::shared_ptr<Event> init_players(
				new SendInitPlayersEvent(game_world.get_step_info()));
			push_event(init_players);
			init_players_not_sent = false;
			statistics_not_sent = true;
			final_state_not_send = true;
		}
	} else if (game_world.get_fase() == FaseType::PLAYING) {
		std::shared_ptr<Event> playing_event(
			new SendStepPlayingEvent(game_world.get_step_info()));
		std::shared_ptr<Event> weapons(
			new SendWeaponsEvent(game_world.get_weapons_info()));
		std::shared_ptr<Event> attacks(
			new SendAttacksInfoEvent(game_world.get_step_info()));
		std::shared_ptr<Event> bomb(
			new SendBombStateEvent(game_world.bomb_info()));
		push_event(playing_event);
		push_event(weapons);
		push_event(attacks);
		push_event(bomb);
	} else {
		std::shared_ptr<Event> final_step(
			new SendFinalStepEvent(game_world.get_step_info()));
		push_event(final_step);

		if (final_state_not_send) {
			std::shared_ptr<Event> playing_event(
				new SendStepPlayingEvent(game_world.get_step_info()));
			std::shared_ptr<Event> attacks(
				new SendAttacksInfoEvent(game_world.get_step_info()));
				// fin, round, cantidad_rounds, porque termino la partida.
			std::shared_ptr<Event> reason_end(
				new SendFinalStateEvent(game_world.get_step_info()));
			push_event(playing_event);
			push_event(attacks);
			push_event(reason_end);
			final_state_not_send = false;
		}
		if ((statistics_not_sent && ((int)CF::time_finish -
			game_world.get_step_info().get_wait() > (int)CF::time_between))
			|| (finished)) {
			std::shared_ptr<Event> stats(
				new SendStatsEvent(game_world, finished));
			statistics_not_sent = false;
			init_players_not_sent = true;
			push_event(stats);
		}
	}
}


// POST: Envia el evento a todos los jugadores de la partida.
void Match::push_event(std::shared_ptr<Event>& event) {
	std::lock_guard<std::mutex> l(m);
	for (auto it = players.begin(); it != players.end(); ++it) {
			std::shared_ptr<Event> to_push = event;
			it->second->push(to_push);
	}
}

// POST: Fuerza la finalizacion de la partida.
void Match::stop_running() {
	syslog(LOG_INFO, "[%s:%i]: Por cerrar"
					 " los hilos de los jugadores "
				 	  , __FILE__, __LINE__);
	std::lock_guard<std::mutex> l(m);
	for (auto it = players.begin(); it != players.end(); ++it) {
		it->second->stop_running();
		delete it->second;
	}
	players.clear();
	syslog(LOG_INFO, "[%s:%i]: Se cerraron"
					 " los hilos de los jugadores "
				 	  , __FILE__, __LINE__);
	to_process_events.close();
	finished = true;
}


Match::~Match() {
	stop_running();
	syslog(LOG_INFO, "[%s:%i]: Se elimino el match "
				 	  , __FILE__, __LINE__);
}
