#include "Match.h"

Match::Match(Socket& socket, const std::string& map_type): match_started(false),
				finished(false), last_id(0), game_world(map_type), handler(game_world) {
	game_world.add_player_if_not_full(last_id);
	Player* player = new Player(socket, last_id, to_process_events);
	if (!player)
		throw Exception("No se pudo alocar memoria");
	players[last_id] = player;
	last_id++;
}

void Match::join_player_if_not_full(Socket& skt) {
	std::lock_guard<std::mutex> l(m);
	if (match_started)
		throw ExceptionMatchStarted("El juego ya comenzo");
	game_world.add_player_if_not_full(last_id);
	Player* player = new Player(skt, last_id, to_process_events);
	if (!player) {
		game_world.delete_player(last_id);
		throw Exception("No se pudo alocar memoria");
	}
	players[last_id] = player;
	last_id++;
}

bool Match::is_finished() {
	return finished;
}

void Match::run() {
	try {
		start_game();
		game_loop();
	} catch (std::exception& e) {
		syslog(LOG_CRIT, "[%s:%i]: %s", __FILE__, __LINE__, e.what());
	}
	
}






void Match::start_game() {
	Event event = to_process_events.blocking_pop();
	// bloqueamos para no aceptar mas jugadores. 
	std::lock_guard<std::mutex> l(m);
	match_started = true;
	StartGameHandler game_starter;
	game_starter.handle(event, players, game_world);
}



void Match::game_loop() {
	while (!finished) {
		handle_events();
		game_world.simulate_step();
		std::shared_ptr<Event> players_info(
				new SendPlayersInfoEvent(game_world.get_players_info()));
		push_event(players_info);
	}
}

void Match::handle_events() {
	bool queue_not_empty = true;
	int max_iterations = CF::max_iterations_pop_events;
	int i = 0;
	while (queue_not_empty && max_iterations < i) {
		try {
			Event event = to_process_events.pop();
			handler.handle(event);
			i++;
		} catch(ExceptionEmptyQueue& e) {
			queue_not_empty = false;
		}
	}

}

void Match::push_event(std::shared_ptr<Event>& event) {
	for (auto it = players.begin(); it != players.end(); ++it) {
			it->second->push(event);
	}
}

void Match::stop_running() {
	std::lock_guard<std::mutex> l(m);
	for (auto it = players.begin(); it != players.end(); ++it) {
		it->second->stop_running();
		delete it->second;
		players.erase(it->first);
	}
	finished = true;
}

Match::~Match() {
	stop_running();
}
