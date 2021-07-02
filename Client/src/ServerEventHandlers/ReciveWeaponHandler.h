#ifndef RECIVE_WEAPON_HANDLER_H
#define RECIVE_WEAPON_HANDLER_H

#include <vector>
#include "Event.h"
#include "GameMap.h"
#include "WeaponSprite.h"
#include "FaseType.h"


class ReciveWeaponHandler {
	public:
		ReciveWeaponHandler();

		void handle(Event& event, GameMap& map);

		~ReciveWeaponHandler();

};


#endif
