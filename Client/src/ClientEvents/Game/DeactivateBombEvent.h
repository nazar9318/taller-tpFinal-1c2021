#ifndef _DEACTIVATE_BOMB_EVENT_H
#define _DEACTIVATE_BOMB_EVENT_H

#include "TypesOfEvents.h"
#include "Event.h"
#include <string>


class DeactivateBombEvent: public Event {
	public:
		DeactivateBombEvent();
		~DeactivateBombEvent();
	private:
		DeactivateBombEvent(const DeactivateBombEvent &other) = delete;
		DeactivateBombEvent& operator=(const DeactivateBombEvent &other) = delete;
};

#endif
