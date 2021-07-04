#ifndef STOP_DEACTIVATE_BOMB_EVENT_H
#define STOP_DEACTIVATE_BOMB_EVENT_H

#include "TypesOfEvents.h"
#include "Event.h"
#include <string>

class StopDeactivateBombEvent: public Event {
	public:
		StopDeactivateBombEvent();
		~StopDeactivateBombEvent();
	private:
		StopDeactivateBombEvent(const StopDeactivateBombEvent &other) = delete;
		StopDeactivateBombEvent& operator=(const StopDeactivateBombEvent &other) = delete;
};

#endif
