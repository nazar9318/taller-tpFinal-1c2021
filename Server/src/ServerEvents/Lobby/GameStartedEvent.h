#ifndef _GAME_STARTED_EVENT_H
#define _GAME_STARTED_EVENT_H

#include "TypesOfEvents.h"
#include "Event.h"
#include <string>


class GameStartedEvent: public Event {
	public:
		GameStartedEvent();
		~GameStartedEvent();
	private:
		GameStartedEvent(const GameStartedEvent &other) = delete;
		GameStartedEvent& operator=(const GameStartedEvent &other) = delete;
};

#endif
