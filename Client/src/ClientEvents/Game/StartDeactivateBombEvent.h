#ifndef START_DEACTIVATE_BOMB_EVENT_H
#define START_DEACTIVATE_BOMB_EVENT_H

#include "TypesOfEvents.h"
#include "Event.h"
#include <string>

class StartDeactivateBombEvent: public Event {
	public:
		StartDeactivateBombEvent();
		~StartDeactivateBombEvent();
	private:
		StartDeactivateBombEvent(const StartDeactivateBombEvent &other) = delete;
		StartDeactivateBombEvent& operator=(const StartDeactivateBombEvent &other) = delete;
};

#endif
