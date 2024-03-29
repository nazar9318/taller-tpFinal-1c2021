#include "Protocol.h"

Protocol::Protocol() {}

Event Protocol::recv_event(Socket& socket){
	uint16_t len_msg;
	socket.recv_message((char*)&len_msg, 2);
	len_msg = ntohs(len_msg);

	std::vector<char> buf(len_msg); 
	socket.recv_message(&buf[0], (unsigned)len_msg);

	return Event(buf, len_msg);
}


void Protocol::send_event(Socket& socket, std::vector<char> msg){
	uint16_t len = htons((uint16_t)msg.size());
	socket.send_message((char*)&len, 2);
	socket.send_message(msg.data(), (unsigned int)msg.size());
}

Protocol::~Protocol() {}
