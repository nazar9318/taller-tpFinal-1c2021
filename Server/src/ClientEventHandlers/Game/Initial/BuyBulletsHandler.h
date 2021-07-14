#ifndef BUY_BULLETS_HANDLER_H
#define BUY_BULLETS_HANDLER_H

#include "GameWorld.h"
#include "Event.h"

class BuyBulletsHandler {
	public:
		BuyBulletsHandler();

		void handle(Event& event, GameWorld& world);

		~BuyBulletsHandler();
};


#endif
