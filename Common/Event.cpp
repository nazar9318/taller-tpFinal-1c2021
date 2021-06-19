#include "Event.h"

Event::Event(std::vector<char> msg, size_t size):msg(msg), size(size){}
Event::Event(){}

char Event::get_type() {
	return msg[0];
}

std::vector<char> Event::get_msg() {
	return msg;
}

int Event::get_id(){
	return client_id;
}

void Event::add_client_id(int id) {
	client_id = id;
}


Event::~Event() {}
