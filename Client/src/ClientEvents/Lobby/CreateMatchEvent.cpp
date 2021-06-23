#include "CreateMatchEvent.h"
#include <syslog.h>

CreateMatchEvent::CreateMatchEvent(std::string match_name, std::string map_name) {
	this->msg.push_back((char)ClientTypeEvent::CREATE);
	std::copy(match_name.begin(), match_name.end(), std::back_inserter(this->msg));
	this->msg.push_back('\0');
	std::copy(map_name.begin(), map_name.end(), std::back_inserter(this->msg));
	this->msg.push_back('\0');
	syslog(LOG_INFO, "[%s:%i]: Se crea un createEvent %s"
			";%s", __FILE__, __LINE__, &(msg[1]), &(msg[match_name.length() + 1]));
}

CreateMatchEvent::~CreateMatchEvent() {}
