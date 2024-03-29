#include "ReceiveFinalStateHandler.h"
#include <iostream>

ReceiveFinalStateHandler::ReceiveFinalStateHandler() {}

void ReceiveFinalStateHandler::handle(FaseType& fase, Event& event, GameMap& map, ClientBomb& bomb) {
	std::vector<char> event_msg = event.get_msg();
	char reason_finished = event_msg[1];

	if (reason_finished == ReasonFinish::TEAM_ELIMINATED) {
		Team team_eliminated = (Team)event_msg[2];
		team_eliminated = team_eliminated; //Para que el compilador no grite
	} else if (reason_finished == ReasonFinish::BOMB_ENDED) {
		BombState bomb_state = (BombState)event_msg[2];
    if(bomb_state == BombState::DEACTIVATED){
			bomb.set_deactivated_state();
    } else if(bomb_state == BombState::EXPLOTED){
			bomb.set_exploted_state();
    }
	}
}

ReceiveFinalStateHandler::~ReceiveFinalStateHandler() {}
