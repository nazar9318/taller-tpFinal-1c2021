#include "Protocol.h"

#include <vector>
#include <syslog.h>
#include <string>


#define ASCII_DIFFERENCE 49

Protocol::Protocol() {}



// POST: Envia un mensaje cualquiera compuesto por dos bytes con
//       el tamanio y luego el contenido de msg. 
void Protocol::send_msg(Socket& socket, char type, const std::string& msg) const {
	socket.send_message((char*)&type, 1);
	uint16_t len = htons((uint16_t)msg.length());
	socket.send_message((char*)&len, 2);
	socket.send_message(msg.c_str(), msg.length());
}

// POST: Recibe un mensaje cualquiera compuesto por dos bytes
//       con el tamanio y luego el mensaje que se carga en msg.
void Protocol::recv_message(Socket& socket, char type, std::string& msg) const {
	// FALTA LOGICA CON TYPE
	uint16_t len_msg;
	socket.recv_message((char*)&len_msg, 2);
	len_msg = ntohs(len_msg);
	/*
	if (len_msg == 0xffff)
		throw ExceptionInvalidCommand("Ocurrio un error de comandos.");
	*/
	std::vector<char> buf(len_msg+1);
	socket.recv_message(&buf[0], (unsigned)len_msg);
	buf[len_msg] = '\0';
	msg = &buf[0];
}


void Protocol::recv_event(Socket& socket, ModelEvent& event) {}




Protocol::~Protocol() {}
