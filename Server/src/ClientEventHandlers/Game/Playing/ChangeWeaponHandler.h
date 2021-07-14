#ifndef _CHANGE_WEAPON_HANDLER_H
#define _CHANGE_WEAPON_HANDLER_H

#include "GameWorld.h"
#include "Event.h"

class ChangeWeaponHandler {
	public:
		ChangeWeaponHandler();

		void handle(Event& event, GameWorld& world);

		~ChangeWeaponHandler();

};


#endif
