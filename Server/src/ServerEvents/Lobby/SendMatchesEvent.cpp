#include "SendMatchesEvent.h"

// POST: El mensaje se construye como: 
//		nombre_match1'\0'nombre_match2'\0'...
SendMatchesEvent::SendMatchesEvent(const std::list<std::string>& matches_info) {
	this->msg.push_back((char)ModelTypeEvent::SEND_MATCHES);
	for (auto name = matches_info.begin(); name != matches_info.end(); name++){
		for (auto it = name->begin(); it != name->end(); it++){
			this->msg.push_back(*it);
		}
		this->msg.push_back('\0');
	}
}

SendMatchesEvent::~SendMatchesEvent() {}
