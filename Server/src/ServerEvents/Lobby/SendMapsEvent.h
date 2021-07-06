#ifndef _SEND_MAPS_EVENT_H
#define _SEND_MAPS_EVENT_H

#include "TypesOfEvents.h"
#include "Event.h"
#include "Configuration.h"
#include <list>
#include <string>


class SendMapsEvent: public Event {
	public:
		// POST: El mensaje se construye como: 
		//		nombre_map1'\0'nombre_map2'\0'...
		SendMapsEvent(const std::list<std::string>& maps);
		~SendMapsEvent();
	private:
		SendMapsEvent(const SendMapsEvent &other) = delete;
		SendMapsEvent& operator=(const SendMapsEvent &other) = delete;
};

#endif
