#include "ReceiveFinalStateHandler.h"
#include <iostream>

ReceiveFinalStateHandler::ReceiveFinalStateHandler() {}

void ReceiveFinalStateHandler::handle(FaseType& fase, Event& event, GameMap& map, ClientBomb& bomb) {
	std::vector<char> event_msg = event.get_msg();
	char reason_finished = event_msg[1];

	if (reason_finished == ReasonFinish::TEAM_ELIMINATED) {
		Team team_eliminated = (Team)event_msg[2];
		team_eliminated = team_eliminated; //Hay que borrar esto, lo hago para que no grite unused variable
		std::cout << "Se elimino un team" << '\n';
	} else if (reason_finished == ReasonFinish::BOMB_ENDED) {
		BombState bomb_state = (BombState)event_msg[2];
    if(bomb_state == BombState::DEACTIVATED){
			bomb.set_deactivated_state();
			std::cout << "Se desactivo la bomba" << '\n';
    } else if(bomb_state == BombState::EXPLOTED){
			bomb.set_exploted_state();
			std::cout << "Exploto la bomba" << '\n';
    }
	}
}

ReceiveFinalStateHandler::~ReceiveFinalStateHandler() {}
