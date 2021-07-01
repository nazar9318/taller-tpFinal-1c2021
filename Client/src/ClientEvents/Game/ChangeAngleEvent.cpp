#include "ChangeAngleEvent.h"

ChangeAngleEvent::ChangeAngleEvent(int angle) {
	this->msg.push_back((char)ClientTypeEvent::ROTATE);

	//angle is circular in 360 degrees
	uint16_t angle_degrees = angle % 360;
	this->msg.push_back(*((char*)&angle_degrees));
	this->msg.push_back(*((char*)&angle_degrees + 1));
}

ChangeAngleEvent::~ChangeAngleEvent() {}
