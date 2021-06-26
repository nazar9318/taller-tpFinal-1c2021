#ifndef _DROP_WEAPON_EVENT_H
#define _DROP_WEAPON_EVENT_H

#include "TypesOfEvents.h"
#include "Event.h"
#include <string>


class DropWeaponEvent: public Event {
	public:

		DropWeaponEvent();
		~DropWeaponEvent();
	private:
		DropWeaponEvent(const DropWeaponEvent &other) = delete;
		DropWeaponEvent& operator=(const DropWeaponEvent &other) = delete;
};

#endif
