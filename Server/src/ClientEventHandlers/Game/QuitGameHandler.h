#ifndef _QUIT_GAME_HANDLER_H
#define _QUIT_GAME_HANDLER_H

#include "GameWorld.h"
#include "Event.h"

class QuitGameHandler {
	public:
		QuitGameHandler();

		void handle(Event& event, GameWorld& world);

		~QuitGameHandler();

};


#endif
