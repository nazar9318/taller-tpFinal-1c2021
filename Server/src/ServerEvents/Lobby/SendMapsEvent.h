#ifndef _SEND_MAPS_EVENT_H
#define _SEND_MAPS_EVENT_H

#include "TypesOfEvents.h"
#include "Event.h"
#include "Configuration.h"
#include <list>
#include <string>


class SendMapsEvent: public Event {
	public:
		SendMapsEvent(std::list<std::string> maps);
		~SendMapsEvent();
	private:
		SendMapsEvent(const SendMapsEvent &other) = delete;
		SendMapsEvent& operator=(const SendMapsEvent &other) = delete;
};

#endif
