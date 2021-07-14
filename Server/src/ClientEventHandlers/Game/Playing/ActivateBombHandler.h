#ifndef _ACTIVATE_BOMB_HANDLER_H
#define _ACTIVATE_BOMB_HANDLER_H

#include "GameWorld.h"
#include "Event.h"

class ActivateBombHandler {
	public:
		ActivateBombHandler();

		void handle(Event& event, GameWorld& world);

		~ActivateBombHandler();
};


#endif
