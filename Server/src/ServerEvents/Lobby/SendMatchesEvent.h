#ifndef _SEND_MATCHES_EVENT_H
#define _SEND_MATCHES_EVENT_H

#include "TypesOfEvents.h"
#include "Event.h"
#include <list>
#include <string>


class SendMatchesEvent: public Event {
	public:
		// POST: El mensaje se construye como: 
		//		nombre_match1'\0'nombre_match2'\0'...
		SendMatchesEvent(const std::list<std::string>& matches_info);
		~SendMatchesEvent();
	private:
		SendMatchesEvent(const SendMatchesEvent &other) = delete;
		SendMatchesEvent& operator=(const SendMatchesEvent &other) = delete;
};

#endif
