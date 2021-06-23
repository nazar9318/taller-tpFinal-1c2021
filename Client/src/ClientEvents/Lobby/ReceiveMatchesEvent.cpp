#include "ReceiveMatchesEvent.h"
#include <syslog.h>

ReceiveMatchesEvent::ReceiveMatchesEvent() {
	this->msg.push_back((char)ClientTypeEvent::GET_MATCHES);
}

ReceiveMatchesEvent::~ReceiveMatchesEvent() {}
