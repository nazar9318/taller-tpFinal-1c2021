#include "ClientEvent.h"



ClientEvent::ClientEvent() {}

//ClientEvent::ClientEvent(ClientEvent &&other): msg(std::move(other.msg)), type_msg(std::move(other.type_msg)) {}


char ClientEvent::type() {
	return type_msg;
}
std::string ClientEvent::to_string() {
	return "a";
}
ClientEvent::~ClientEvent() {}
