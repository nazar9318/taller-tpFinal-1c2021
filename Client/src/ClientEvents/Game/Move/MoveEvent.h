#ifndef _MOVE_EVENT_H
#define _MOVE_EVENT_H

#include <string>
#include <syslog.h>

#include "Event.h"
#include "TypesOfEvents.h"

class MoveEvent:public Event{
	public:
		MoveEvent(char direction);
		~MoveEvent();

	private:
		MoveEvent(const MoveEvent &other) = delete;
		MoveEvent& operator=(const MoveEvent &other) = delete;
};

#endif
