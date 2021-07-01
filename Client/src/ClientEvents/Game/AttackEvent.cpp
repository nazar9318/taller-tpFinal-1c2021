#include "AttackEvent.h"


AttackEvent::AttackEvent() {
	this->msg.push_back((char)ClientTypeEvent::START_ATTACKING); 
	
	//angle is circular in 360 degrees
	/*uint16_t angle_degrees = angle % 360; 
	this->msg.push_back(*((char*)&angle_degrees)); 
	this->msg.push_back(*((char*)&angle_degrees + 1)); */
}


AttackEvent::~AttackEvent() {}
