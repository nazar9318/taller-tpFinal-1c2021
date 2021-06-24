#ifndef _START_GAME_EVENT_H
#define _START_GAME_EVENT_H

#include <string>
#include <syslog.h>

#include "Event.h"
#include "TypesOfEvents.h"

class StartGameEvent: public Event{
	public:
		StartGameEvent();
		~StartGameEvent();
		
	private:
		StartGameEvent(const StartGameEvent &other) = delete;
		StartGameEvent& operator=(const StartGameEvent &other) = delete;
};

#endif
