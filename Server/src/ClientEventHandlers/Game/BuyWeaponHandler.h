#ifndef BUY_WEAPON_HANDLER_H
#define BUY_WEAPON_HANDLER_H

#include "GameWorld.h"
#include "Event.h"

class BuyWeaponHandler {
	public:
		BuyWeaponHandler();

		void handle(Event& event, GameWorld& world);

		~BuyWeaponHandler();

};


#endif
