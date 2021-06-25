#include "JoinMatchEvent.h"
#include <syslog.h>

JoinMatchEvent::JoinMatchEvent(std::string match_name) {
	this->msg.push_back((char)ClientTypeEvent::JOIN);
	std::copy(match_name.begin(), match_name.end(), std::back_inserter(this->msg));
	this->msg.push_back('\0');
	syslog(LOG_INFO, "[%s:%i]: Se crea un joinMatchEvent %s"
			, __FILE__, __LINE__, &(msg[1]));
}

JoinMatchEvent::~JoinMatchEvent() {}
