#include "SendWeaponsEvent.h"

SendWeaponsEvent::SendWeaponsEvent(std::vector<Position*> weapons_info) {
	this->msg.push_back((char)ModelTypeEvent::SEND_WEAPONS);
	for (auto it = weapons_info.begin(); it != weapons_info.end(); ++it) {
		int x_pos = (*it)->get_x();
		int y_pos = -1 * (*it)->get_y();
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
