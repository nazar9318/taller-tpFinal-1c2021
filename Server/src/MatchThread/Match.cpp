#include "Match.h"

// POST: Crea una partida con el tipo de mapa correspondiente
//       y agrega al jugador a la misma.
Match::Match(Socket& socket, const std::string& map_type,
			const std::string& player_name): match_started(false),
			finished(false), last_id(0), 
			game_world(map_type), handler(game_world) {
	game_world.add_player_if_not_full(last_id);
	Player* player = new Player(socket, last_id, player_name, to_process_events);
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
	push_event(players_info);
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
		game_loop();
		stop_running();
	} catch (std::exception& e) {
		syslog(LOG_CRIT, "[%s:%i]: %s", __FILE__, __LINE__, e.what());
	}
}


void Match::start_game() {
	while(!match_started) {
		Event event = to_process_events.blocking_pop();
		// bloqueamos para no aceptar mas jugadores. 
		std::lock_guard<std::mutex> l(m);
		match_started = true;
		StartGameHandler game_starter;
		try {
			game_starter.handle(event, players, game_world);
		} catch(ExceptionInvalidCommand& e) {
			std::shared_ptr<Event> error(new ErrorEvent(e.get_type()));
			push_event(error);
			syslog(LOG_CRIT, "[%s:%i]: No hay jugadores suficientes"
						, __FILE__, __LINE__);
			match_started = false;
		}
	}
}



void Match::game_loop() {
	using namespace std::chrono;
	auto begin = steady_clock::now();
	auto end = steady_clock::now(); 
	double t_delta;
	double step_time = 1 / 30; // en segundos

	while (!finished) {
		begin = steady_clock::now();
		handle_events();
		finished = !game_world.simulate_step(step_time);
		std::shared_ptr<Event> players_info(
				new SendStepInfoEvent(game_world.get_step_info()));
		push_event(players_info);
		end = steady_clock::now();
		t_delta = duration<double>(end - begin).count();
		std::this_thread::sleep_for(duration<double>(step_time - t_delta));
	}
}

// POST: Desencola los eventos recibidos por los clientes y los
//       maneja. 
void Match::handle_events() {
	bool queue_not_empty = true;
	int max_iterations = CF::max_iterations_pop_events;
	int i = 0;
	while (queue_not_empty && max_iterations > i) {
		try {
			Event event = to_process_events.pop();
			handler.handle(event);
			i++;
		} catch(ExceptionEmptyQueue& e) {
			queue_not_empty = false;
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
		players.erase(it->first);
	}
	syslog(LOG_INFO, "[%s:%i]: Se cerraron"
					 " los hilos de los jugadores "
				 	  , __FILE__, __LINE__);
	finished = true;
	to_process_events.close();
}


Match::~Match() {
	syslog(LOG_INFO, "[%s:%i]: Se elimino el match "
				 	  , __FILE__, __LINE__);
}
