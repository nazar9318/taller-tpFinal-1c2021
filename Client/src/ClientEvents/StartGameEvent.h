#ifndef _START_GAME_EVENT_H
#define _START_GAME_EVENT_H

#include <string>
#include <syslog.h>

#include "Event.h"
// #include "ClientEvent.h"
#include "TypesOfEvents.h"

class StartGameEvent{

	private:
    std::vector<char> msg;

	public:
		StartGameEvent();
		Event* get_pointer_event();
		Event get_event();

		~StartGameEvent();

	private:
		StartGameEvent(const StartGameEvent &other) = delete;
		StartGameEvent& operator=(const StartGameEvent &other) = delete;
};

#endif
