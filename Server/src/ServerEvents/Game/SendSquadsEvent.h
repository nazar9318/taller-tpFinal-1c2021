#ifndef _SEND_SQUADS_EVENT_H
#define _SEND_SQUADS_EVENT_H

#include "TypesOfEvents.h"
#include "Event.h"
#include <vector>
#include <string>


class SendSquadsEvent: public Event {
	public:
		SendSquadsEvent(std::vector<char> squads);
		~SendSquadsEvent();
	private:
		SendSquadsEvent(const SendSquadsEvent &other) = delete;
		SendSquadsEvent& operator=(const SendSquadsEvent &other) = delete;
};

#endif
