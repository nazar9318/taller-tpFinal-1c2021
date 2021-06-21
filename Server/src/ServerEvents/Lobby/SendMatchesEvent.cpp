#include "SendMatchesEvent.h"

SendMatchesEvent::SendMatchesEvent(std::string matches_info) {
	this->msg.push_back((char)ModelTypeEvent::SEND_MATCHES);
	
	for (auto it = matches_info.begin(); it != matches_info.end(); it++){
		this->msg.push_back(*it);
	}	
}

SendMatchesEvent::~SendMatchesEvent() {}
