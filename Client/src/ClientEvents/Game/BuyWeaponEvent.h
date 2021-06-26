#ifndef _BUY_WEAPON_EVENT_H
#define _BUY_WEAPON_EVENT_H

#include "TypesOfEvents.h"
#include "Event.h"
#include <string>


class BuyWeaponEvent: public Event {
	public:
		BuyWeaponEvent(char weapon);
		~BuyWeaponEvent();
	private:
		BuyWeaponEvent(const BuyWeaponEvent &other) = delete;
		BuyWeaponEvent& operator=(const BuyWeaponEvent &other) = delete;
};

#endif
