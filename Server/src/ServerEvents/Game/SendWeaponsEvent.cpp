#include "SendWeaponsEvent.h"

SendWeaponsEvent::SendWeaponsEvent(std::list<std::unique_ptr<Weapon>>&  weapons_info) {
	this->msg.push_back((char)ModelTypeEvent::SEND_WEAPONS);
	for (auto it = weapons_info.begin(); it != weapons_info.end(); ++it) {

		int x_pos, y_pos;
		(*it)->get_pos(x_pos, y_pos);
		y_pos = y_pos * -1;

		char type = (*it)->get_type();

		this->msg.push_back(*((char*)(&x_pos)));
		this->msg.push_back(*((char*)(&x_pos) + 1));
		this->msg.push_back(*((char*)(&x_pos) + 2));
		this->msg.push_back(*((char*)(&x_pos) + 3));

		this->msg.push_back(*((char*)(&y_pos)));
		this->msg.push_back(*((char*)(&y_pos) + 1));
		this->msg.push_back(*((char*)(&y_pos) + 2));
		this->msg.push_back(*((char*)(&y_pos) + 3));

		this->msg.push_back(type);
	}
}

SendWeaponsEvent::~SendWeaponsEvent() {}
