#ifndef _EXCHANGE_WEAPON_HANDLER_H
#define _EXCHANGE_WEAPON_HANDLER_H

#include "GameWorld.h"
#include "Event.h"

class ExchangeWeaponHandler {
	public:
		ExchangeWeaponHandler();

		void handle(Event& event, GameWorld& world);

		~ExchangeWeaponHandler();

};


#endif
