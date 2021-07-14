#ifndef _START_ATTACKING_HANDLER_H
#define _START_ATTACKING_HANDLER_H

#include "GameWorld.h"
#include "Event.h"

class StartAttackingHandler {
	public:
		StartAttackingHandler();

		void handle(Event& event, GameWorld& world);

		~StartAttackingHandler();

};


#endif
