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
		// Descripcion: Envia todos las armas que estan en el suelo. 
		// POST: El mensaje es de la forma: 
		//       pos0x(int), pos0y(int), type0,
		//       pos1x(int), pos1y(int), type1, ...
		SendWeaponsEvent(const std::list<std::unique_ptr<Weapon>>& weapons_info);
		~SendWeaponsEvent();
	private:
		SendWeaponsEvent(const SendWeaponsEvent &other) = delete;
		SendWeaponsEvent& operator=(const SendWeaponsEvent &other) = delete;
};

#endif
