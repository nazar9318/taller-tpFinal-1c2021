#include "Match.h"

Match::Match(Socket& socket, GameWorldType type): match_started(false),
				finished(false), last_id(0), game_world(GameWorldFactory::create(type)) {
	if (!game_world)
		throw Exception("No se pudo alocar memoria");
	game_world->add_player_if_not_full(last_id);
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
	game_world->add_player_if_not_full(last_id);
	Player* player = new Player(skt, last_id, to_process_events);
	if (!player) {
		game_world->delete_player(last_id);
		throw Exception("No se pudo alocar memoria");
	}
	players[last_id] = player;
	last_id++;
}

bool Match::is_finished() {
	return finished;
}

void Match::run() {

	Event event = to_process_events.blocking_pop();
	if (event.get_type() != TypeOfEvent::START_GAME) {
		finished = true;
		syslog(LOG_INFO, "LLega un evento diferente al esperado, startgame");
		return;
	}
	{
		std::lock_guard<std::mutex> l(m);
		match_started = true;
	}

	std::shared_ptr<Event> starter_event(new Event());
	for (auto it = players.begin(); it != players.end(); ++it) {
		it->second->push(starter_event);
	}


	game_world->start();
	while (!finished) {
		Event event = to_process_events.pop();
		std::unique_ptr<ClientEventHandler> handler = EventHandlerFactory::create(event);
		handler->handle();
	}
		//Enviar a todos los clientes los eventos

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
