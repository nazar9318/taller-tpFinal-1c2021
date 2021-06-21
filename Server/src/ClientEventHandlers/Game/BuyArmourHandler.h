#ifndef BUY_ARMOUR_HANDLER_H
#define BUY_ARMOUR_HANDLER_H

#include "GameWorld.h"
#include "Event.h"

class BuyArmourHandler {
	public:
		BuyArmourHandler();

		void handle(Event& event, GameWorld& world);

		~BuyArmourHandler();

};


#endif
