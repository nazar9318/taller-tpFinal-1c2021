#ifndef _STOP_ACTIVATING_BOMB_HANDLER_H
#define _STOP_ACTIVATING_BOMB_HANDLER_H

#include "GameWorld.h"
#include "Event.h"

class StopActivatingBombHandler {
	public:
		StopActivatingBombHandler();

		void handle(Event& event, GameWorld& world);

		~StopActivatingBombHandler();
};


#endif
