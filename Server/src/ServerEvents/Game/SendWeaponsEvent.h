#ifndef _SEND_WEAPONS_EVENT_H
#define _SEND_WEAPONS_EVENT_H

#include "Position.h"
#include "Event.h"
#include "TypesOfEvents.h"
#include <vector>
#include <list>
#include <memory>
#include "Weapon.h"

class SendWeaponsEvent: public Event {
	public:
		SendWeaponsEvent(std::list<std::unique_ptr<Weapon>>&  weapons_info);
		~SendWeaponsEvent();
	private:
		SendWeaponsEvent(const SendWeaponsEvent &other) = delete;
		SendWeaponsEvent& operator=(const SendWeaponsEvent &other) = delete;
};

#endif
