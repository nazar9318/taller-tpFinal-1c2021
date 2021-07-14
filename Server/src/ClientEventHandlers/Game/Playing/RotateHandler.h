#ifndef _ROTATE_HANDLER_H
#define _ROTATE_HANDLER_H

#include "GameWorld.h"
#include "Event.h"
#include "TypesOfEvents.h"

class RotateHandler {
	public:
		RotateHandler();

		void handle(Event& event, GameWorld& world);

		~RotateHandler();
};


#endif
