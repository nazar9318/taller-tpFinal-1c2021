#include "StartGameHandler.h"

StartGameHandler::StartGameHandler() {
}

// PRE: El evento es del tipo START_GAME
// POST: Inicia la partida en el mundo y le envia a todos
//       los jugadores la informacion del estado del mundo.
void StartGameHandler::handle(Event& event,
		 std::map<char, Player*>& players, GameWorld& game_world) {
	if (event.get_type() == ClientTypeEvent::CREATOR_ABANDONS) {
		throw ExceptionInvalidCommand("El creador abandono la partida",
							ServerError::CREATOR_ABANDONS_MATCH);
	} else if (event.get_type() != ClientTypeEvent::START_GAME) {
		throw Exception("[%s:%i]: LLega un evento "
				"diferente al esperado, startgame",
						 __FILE__, __LINE__);
	}

	game_world.start();
	std::shared_ptr<Event> starter_event(new GameStartedEvent());
	int x_size;
	int y_size;
	game_world.get_limits(x_size, y_size);
	
	std::shared_ptr<Event> configs(new SendInitialConfigsEvent());
	std::shared_ptr<Event> game_map(
			new SendFullMapEvent(game_world.get_ground_info(), x_size, y_size));

	std::shared_ptr<Event> weapons(
			new SendWeaponsEvent(game_world.get_weapons_info()));

	std::shared_ptr<Event> squads(
			new SendSquadsEvent(game_world.get_squads()));

	for (auto it = players.begin(); it != players.end(); ++it) {
		std::shared_ptr<Event> event_start = starter_event;
		std::shared_ptr<Event> event_map = game_map;
		std::shared_ptr<Event> event_weapon = weapons;
		std::shared_ptr<Event> event_squads = squads;
		std::shared_ptr<Event> event_configs = configs;
		it->second->push(event_start);
		it->second->push(event_map);
		it->second->push(event_weapon);
		it->second->push(event_squads);
		it->second->push(event_configs);
	}
}

StartGameHandler::~StartGameHandler(){
}
