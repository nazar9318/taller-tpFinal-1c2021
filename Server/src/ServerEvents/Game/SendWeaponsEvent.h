#ifndef _SEND_WEAPONS_EVENT_H
#define _SEND_WEAPONS_EVENT_H

#include "Position.h"
#include "Event.h"
#include "TypesOfEvents.h"
#include <vector>

class SendWeaponsEvent: public Event {
	public:
		SendWeaponsEvent(std::vector<Position*> weapons_info);
		~SendWeaponsEvent();
	private:
		SendWeaponsEvent(const SendWeaponsEvent &other) = delete;
		SendWeaponsEvent& operator=(const SendWeaponsEvent &other) = delete;
};

#endif
