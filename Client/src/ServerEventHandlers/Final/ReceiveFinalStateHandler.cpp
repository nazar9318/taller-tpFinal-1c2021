#include "ReceiveFinalStateHandler.h"

ReceiveFinalStateHandler::ReceiveFinalStateHandler() {}

void ReceiveFinalStateHandler::handle(FaseType& fase, Event& event, GameMap& map) {
	/*
	std::vector<char> event_msg = event.get_msg();
	char reason_finished = event_msg[1];
	if (reason_finished == ReasonFinish::TEAM_ELIMINATED) {
		Team team_eliminated = (Team)event_msg[2];
	} else if (reason_finished == ReasonFinish::BOMB_ENDED) {
		BombState bomb_state = (BombState)event_msg[2];
		// exploted o deactivated. 
	}*/
}

ReceiveFinalStateHandler::~ReceiveFinalStateHandler() {}
