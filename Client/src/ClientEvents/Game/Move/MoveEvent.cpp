#include "MoveEvent.h"

MoveEvent::MoveEvent(char direction){
	this->msg.push_back(ClientTypeEvent::MOVE);
	this->msg.push_back(direction);
}

MoveEvent::~MoveEvent(){}
