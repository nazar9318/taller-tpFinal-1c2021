#include "ModelEvent.h"


ModelEvent::ModelEvent(std::vector<char> msg, size_t size): msg(msg), size(size){}
ModelEvent::ModelEvent(){}

char ModelEvent::get_type() {
	return msg[0];
}

std::vector<char> ModelEvent::get_msg() {
	return msg;
}

ModelEvent::~ModelEvent() {}
