#include "StartGameHandler.h"

StartGameHandler::StartGameHandler() {
}

// PRE: El evento es del tipo START_GAME
// POST: Inicia la partida en el mundo y le envia a todos
//       los jugadores la informacion del estado del mundo.
void StartGameHandler::handle(Event& event,
		 std::map<char, Player*>& players, GameWorld& game_world) {
	if (event.get_type() != ClientTypeEvent::START_GAME) {
		throw Exception("[%s:%i]: LLega un evento "
				"diferente al esperado, startgame",
						 __FILE__, __LINE__);
	}
	game_world.start();

	std::shared_ptr<Event> starter_event(new GameStartedEvent());
	int x_size;
	int y_size;
	game_world.get_limits(x_size, y_size);
	std::shared_ptr<Event> game_map(
			new SendFullMapEvent(game_world.get_ground_info(), x_size, y_size));

	std::shared_ptr<Event> weapons(
			new SendWeaponsEvent(game_world.get_weapons_info()));

	for (auto it = players.begin(); it != players.end(); ++it) {
		std::shared_ptr<Event> event_start = starter_event;
		std::shared_ptr<Event> event_map = game_map;
		std::shared_ptr<Event> event_weapon = weapons;
		it->second->push(event_start);
		it->second->push(event_map);
		it->second->push(weapons);
	}
}

StartGameHandler::~StartGameHandler(){
}
