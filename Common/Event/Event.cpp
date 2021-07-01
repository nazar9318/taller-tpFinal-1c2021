#include "Event.h"

Event::Event(std::vector<char> msg, size_t size): msg(msg), size(size) {}
Event::Event() {}

char Event::get_type() {
	return msg[0];
}

std::vector<char> Event::get_msg() {
	return msg;
}

char* Event::get_data() {
	return msg.data();
}

char Event::get_id(){
	return client_id;
}

void Event::add_client_id(char id) {
	client_id = id;
}

size_t Event::get_size() {
	return size;
}


void Event::push_back(int a_number) {
	msg.push_back(*((char*)(&a_number)));
	msg.push_back(*((char*)(&a_number) + 1));
	msg.push_back(*((char*)(&a_number) + 2));
	msg.push_back(*((char*)(&a_number) + 3));
}


Event::~Event() {}
