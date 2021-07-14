#ifndef _DEACTIVATE_BOMB_HANDLER_H
#define _DEACTIVATE_BOMB_HANDLER_H

#include "GameWorld.h"
#include "Event.h"

class DeactivateBombHandler {
	public:
		DeactivateBombHandler();

		void handle(Event& event, GameWorld& world);

		~DeactivateBombHandler();
};


#endif
