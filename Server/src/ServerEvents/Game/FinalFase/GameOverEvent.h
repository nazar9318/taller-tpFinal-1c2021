#ifndef _GAME_OVER_EVENT_H
#define _GAME_OVER_EVENT_H

#include "TypesOfEvents.h"
#include "Event.h"
#include <vector>
#include <string>

class GameOverEvent: public Event {
	public:
		GameOverEvent();
		~GameOverEvent();
	private:
		GameOverEvent(const GameOverEvent &other) = delete;
		GameOverEvent& operator=(const GameOverEvent &other) = delete;
};

#endif
