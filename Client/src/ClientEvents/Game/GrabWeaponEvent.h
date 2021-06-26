#ifndef _GRAB_WEAPON_EVENT_H
#define _GRAB_WEAPON_EVENT_H

#include "TypesOfEvents.h"
#include "Event.h"
#include <string>


class GrabWeaponEvent: public Event {
	public:

		GrabWeaponEvent();
		~GrabWeaponEvent();
	private:
		GrabWeaponEvent(const GrabWeaponEvent &other) = delete;
		GrabWeaponEvent& operator=(const GrabWeaponEvent &other) = delete;
};

#endif
