#ifndef _SEND_MATCHES_EVENT_H
#define _SEND_MATCHES_EVENT_H

#include "TypesOfEvents.h"
#include "Event.h"
#include <list>
#include <string>


class SendMatchesEvent: public Event {
	public:
		SendMatchesEvent(std::list<std::string> matches_info);
		~SendMatchesEvent();
	private:
		SendMatchesEvent(const SendMatchesEvent &other) = delete;
		SendMatchesEvent& operator=(const SendMatchesEvent &other) = delete;
};

#endif
