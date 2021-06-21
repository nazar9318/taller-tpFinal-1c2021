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
				new SendFullMapEvent(game_world.get_all_info()));
	
	for (auto it = players.begin(); it != players.end(); ++it) {
		it->second->push(starter_event);
	}
}



StartGameHandler::~StartGameHandler(){}
