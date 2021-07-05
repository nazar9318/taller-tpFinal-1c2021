#ifndef _STOP_DEACTIVATING_BOMB_HANDLER_H
#define _STOP_DEACTIVATING_BOMB_HANDLER_H

#include "GameWorld.h"
#include "Event.h"

class StopDeactivatingBombHandler {
	public:
		StopDeactivatingBombHandler();

		void handle(Event& event, GameWorld& world);

		~StopDeactivatingBombHandler();
};


#endif
