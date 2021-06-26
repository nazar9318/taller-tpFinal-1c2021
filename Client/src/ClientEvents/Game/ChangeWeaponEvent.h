#ifndef _CHANGE_WEAPON_EVENT_H
#define _CHANGE_WEAPON_EVENT_H

#include "TypesOfEvents.h"
#include "Event.h"
#include <string>


class ChangeWeaponEvent: public Event {
	public:

		ChangeWeaponEvent();
		~ChangeWeaponEvent();
	private:
		ChangeWeaponEvent(const ChangeWeaponEvent &other) = delete;
		ChangeWeaponEvent& operator=(const ChangeWeaponEvent &other) = delete;
};

#endif
