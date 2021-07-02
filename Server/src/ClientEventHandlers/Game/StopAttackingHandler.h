#ifndef _STOP_ATTACKING_HANDLER_H
#define _STOP_ATTACKING_HANDLER_H

#include "GameWorld.h"
#include "Event.h"

class StopAttackingHandler {
	public:
		StopAttackingHandler();

		void handle(Event& event, GameWorld& world);

		~StopAttackingHandler();

};


#endif
