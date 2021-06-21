#ifndef _MOVE_EVENT_H
#define _MOVE_EVENT_H

#include <string>
#include <syslog.h>

#include "Event.h"
#include "TypesOfEvents.h"

class MoveEvent{

	private:
    std::vector<char> msg;

	public:
		MoveEvent(/*Direction& direction*/);

    Event get_event();

		~MoveEvent();

	private:
		MoveEvent(const MoveEvent &other) = delete;
		MoveEvent& operator=(const MoveEvent &other) = delete;
};

#endif
