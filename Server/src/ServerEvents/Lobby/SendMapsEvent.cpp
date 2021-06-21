#include "SendMapsEvent.h"

SendMapsEvent::SendMapsEvent(std::list<std::string> maps) {
	this->msg.push_back((char)ModelTypeEvent::SEND_MAPS);
	for (auto it = maps.begin(); it != maps.end(); it++){
		for (auto it_str = it->begin(); it_str != it->end(); ++it_str) {
			this->msg.push_back(*it_str);
		}
		this->msg.push_back(';');
	}	
}

SendMapsEvent::~SendMapsEvent() {}
