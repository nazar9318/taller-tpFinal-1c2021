#include "Match.h"




Match::Match(Socket& socket, GameWorldType type): match_started(false), 
				finished(false), last_id(0), game_world(GameWorldFactory::create(type)) {
	if (!game_world)
		throw Exception("No se pudo alocar memoria");
	Player* player = new Player(socket, last_id, to_process_events);
	if (!player)
		throw Exception("No se pudo alocar memoria");
	players[last_id] = player;
	game_world->add_player_if_not_full(last_id);
	last_id++;
}

void Match::join_player_if_not_full(Socket& skt) {
	std::lock_guard<std::mutex> l(m);
	if (match_started)
		throw ExceptionMatchStarted("El juego ya comenzo");
	game_world->add_player_if_not_full(last_id);	
	Player* player = new Player(skt, last_id, to_process_events);
	if (!player) {
		throw Exception("No se pudo alocar memoria");
		game_world->delete_player(last_id);
	}
	players[last_id] = player;
	last_id++;
}

bool Match::is_finished() {
	return finished;
}

void Match::run() {



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