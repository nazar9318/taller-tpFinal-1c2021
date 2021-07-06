#include "SendMapsEvent.h"


// POST: El mensaje se construye como: 
//		nombre_map1'\0'nombre_map2'\0'...
SendMapsEvent::SendMapsEvent(const std::list<std::string>& maps) {
	this->msg.push_back(ModelTypeEvent::SEND_MAPS);
	for (auto it = maps.begin(); it != maps.end(); it++){
		for (auto it_str = it->begin(); it_str != it->end(); ++it_str) {
			this->msg.push_back(*it_str);
		}
		this->msg.push_back('\0');
	}	
}

SendMapsEvent::~SendMapsEvent() {}
