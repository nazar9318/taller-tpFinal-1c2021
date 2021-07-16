#include "AttackEvent.h"

AttackEvent::AttackEvent() {
	this->msg.push_back((char)ClientTypeEvent::START_ATTACKING); 
}

AttackEvent::~AttackEvent() {}
