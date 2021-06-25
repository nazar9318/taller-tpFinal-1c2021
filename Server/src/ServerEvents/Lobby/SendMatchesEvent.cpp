#include "SendMatchesEvent.h"

SendMatchesEvent::SendMatchesEvent(std::list<std::string> matches_info) {
	this->msg.push_back((char)ModelTypeEvent::SEND_MATCHES);
	for (auto name = matches_info.begin(); name != matches_info.end(); name++){
		for (auto it = name->begin(); it != name->end(); it++){
			this->msg.push_back(*it);
		}
		this->msg.push_back('\0');
	}
}

SendMatchesEvent::~SendMatchesEvent() {}
