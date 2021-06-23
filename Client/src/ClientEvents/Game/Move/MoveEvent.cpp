#include "MoveEvent.h"

MoveEvent::MoveEvent(Direction direction){
	this->msg.push_back((char)ClientTypeEvent::MOVE); 
	this->msg.push_back((char)direction);
}

MoveEvent::~MoveEvent(){}
