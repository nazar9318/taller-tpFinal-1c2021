#include "ClientEvent.h"



ClientEvent::ClientEvent(TypeOfEvent t): type_msg(t) {}

//ClientEvent::ClientEvent(ClientEvent &&other): msg(std::move(other.msg)), type_msg(std::move(other.type_msg)) {}


char ClientEvent::get_type() {
	return type_msg;
}
std::string ClientEvent::to_string() {
	return msg;
}

void ClientEvent::add_client_id(int id) {
	client_id = id;
}


ClientEvent::~ClientEvent() {}
