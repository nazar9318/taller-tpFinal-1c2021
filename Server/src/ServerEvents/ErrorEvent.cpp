#include "ErrorEvent.h"

ErrorEvent::ErrorEvent(ServerError type_error) {
	this->msg.push_back((char)ModelTypeEvent::ERROR);
	this->msg.push_back((char)type_error);
}

ErrorEvent::~ErrorEvent() {}
