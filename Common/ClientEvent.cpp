#include "ClientEvent.h"



ClientEvent::ClientEvent(std::vector<char> msg, size_t size):msg(msg), size(size){}
ClientEvent::ClientEvent(){}

//ClientEvent::ClientEvent(ClientEvent &&other): msg(std::move(other.msg)), type_msg(std::move(other.type_msg)) {}


char ClientEvent::get_type() {
	return msg[0];
}

std::vector<char> ClientEvent::to_string() {
	return msg;
}

int ClientEvent::get_id(){
	return client_id;
}

void ClientEvent::add_client_id(int id) {
	client_id = id;
}


ClientEvent::~ClientEvent() {}
