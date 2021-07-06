#include "SendWeaponsEvent.h"
#include <iostream>

// Descripcion: Envia todos las armas que estan en el suelo. 
// POST: El mensaje es de la forma: 
//       pos0x(int), pos0y(int), type0,
//       pos1x(int), pos1y(int), type1, ...
SendWeaponsEvent::
SendWeaponsEvent(const std::list<std::unique_ptr<Weapon>>& weapons_info) {
	this->msg.push_back((char)ModelTypeEvent::SEND_WEAPONS);
	for (auto it = weapons_info.begin(); it != weapons_info.end(); ++it) {
		int x_pos, y_pos;
		(*it)->get_pos(x_pos, y_pos);
		y_pos = y_pos * (-1);
		char type = (*it)->get_type();
		push_back(x_pos);
		push_back(y_pos);
		this->msg.push_back(type);
	}
}

SendWeaponsEvent::~SendWeaponsEvent() {}
