#include "SendFullMapEvent.h"
#include <iostream>
SendFullMapEvent::SendFullMapEvent(std::vector<Position*> map_info,
			 int x_lenght, int y_lenght) {
	this->msg.push_back((char)ModelTypeEvent::SEND_FULL_MAP);

	this->msg.push_back(*((char*)(&x_lenght)));
	this->msg.push_back(*((char*)(&x_lenght) + 1));
	this->msg.push_back(*((char*)(&x_lenght) + 2));
	this->msg.push_back(*((char*)(&x_lenght) + 3));

	this->msg.push_back(*((char*)(&y_lenght)));
	this->msg.push_back(*((char*)(&y_lenght) + 1));
	this->msg.push_back(*((char*)(&y_lenght) + 2));
	this->msg.push_back(*((char*)(&y_lenght) + 3));

	for (auto it = map_info.begin(); it != map_info.end(); ++it) {
		int x_pos = (*it)->get_x();
		int y_pos = (-1) * (*it)->get_y();
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

SendFullMapEvent::~SendFullMapEvent() {}
