#ifndef MOVE_HANDLER_H
#define MOVE_HANDLER_H

#include "GameWorld.h"
#include "Event.h"

class MoveHandler {
	public:
		MoveHandler();

		void handle(Event& event, GameWorld& world);

		~MoveHandler();

};


#endif
