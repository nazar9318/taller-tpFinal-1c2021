#ifndef _GRAB_WEAPON_HANDLER_H
#define _GRAB_WEAPON_HANDLER_H

#include "GameWorld.h"
#include "Event.h"

class GrabWeaponHandler {
	public:
		GrabWeaponHandler();

		void handle(Event& event, GameWorld& world);

		~GrabWeaponHandler();

};


#endif
