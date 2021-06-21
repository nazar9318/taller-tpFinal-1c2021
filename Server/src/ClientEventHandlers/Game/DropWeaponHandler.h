#ifndef _DROP_WEAPON_HANDLER_H
#define _DROP_WEAPON_HANDLER_H

#include "GameWorld.h"
#include "Event.h"

class DropWeaponHandler {
	public:
		DropWeaponHandler();

		void handle(Event& event, GameWorld& world);

		~DropWeaponHandler();

};


#endif
