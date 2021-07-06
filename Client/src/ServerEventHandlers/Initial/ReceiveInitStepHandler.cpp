#include "ReceiveInitStepHandler.h"

ReceiveInitStepHandler::ReceiveInitStepHandler(){}


void ReceiveInitStepHandler::handle(FaseType& fase, Event& event, GameMap& map){
	fase = FaseType::INITIAL_FASE; 

	std::vector<char> event_msg = event.get_msg();
	int wait_time = *((int*)&(event_msg[1]));
	wait_time++; //algo para que no me grite el compilador.
}


ReceiveInitStepHandler::~ReceiveInitStepHandler(){}
