#include "StartGameHandler.h"

StartGameHandler::StartGameHandler() {}


void StartGameHandler::handle(Event& event,
		 std::map<char, Player*>& players, GameWorld& game_world) {
	if (event.get_type() != ClientTypeEvent::START_GAME) {
		throw Exception("[%s:%i]: LLega un evento "
				"diferente al esperado, startgame",
						 __FILE__, __LINE__);
	}
	game_world.start();

	std::shared_ptr<Event> starter_event(
				new GameStartedEvent());
	int x_size;
	int y_size;
	game_world.get_limits(x_size, y_size);
	std::shared_ptr<Event> game_map(
				new SendFullMapEvent(game_world.get_ground_info(), x_size, y_size));

	for (auto it = players.begin(); it != players.end(); ++it) {
		std::shared_ptr<Event> event_start = starter_event;
		std::shared_ptr<Event> event_map = game_map;
		it->second->push(event_start);
		it->second->push(event_map);
	}
}

StartGameHandler::~StartGameHandler(){}
