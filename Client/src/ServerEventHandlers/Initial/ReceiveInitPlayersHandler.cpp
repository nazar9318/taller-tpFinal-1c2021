#include "ReceiveInitPlayersHandler.h"

ReceiveInitPlayersHandler::ReceiveInitPlayersHandler(){}


void ReceiveInitPlayersHandler::handle(FaseType& fase, Event& event, GameMap& map){
	fase = FaseType::INITIAL_FASE; 
	std::vector<char> event_msg = event.get_msg();
	for (auto it = event_msg.begin() + 1; it != event_msg.end(); it += 2) {
			char id = *it;
			Team team = (Team)*(it + 1);
			map.add_character_team(id, team);
	}
}


ReceiveInitPlayersHandler::~ReceiveInitPlayersHandler(){}
