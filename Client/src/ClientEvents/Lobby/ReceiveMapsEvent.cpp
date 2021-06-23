#include "ReceiveMapsEvent.h"
#include <syslog.h>

ReceiveMapsEvent::ReceiveMapsEvent() {
	this->msg.push_back((char)ClientTypeEvent::GET_MAPS);
}

ReceiveMapsEvent::~ReceiveMapsEvent() {}

