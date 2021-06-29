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



Event::~Event() {}
