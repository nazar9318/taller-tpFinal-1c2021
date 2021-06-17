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
	if (len_msg == 0xffff)
		throw ExceptionInvalidCommand("Ocurrio un error de comandos.");
	std::vector<char> buf(len_msg+1);
	socket.recv_message(&buf[0], (unsigned)len_msg);
	buf[len_msg] = '\0';
	msg = &buf[0];
}


void Protocol::recv_event(Socket& socket, ModelEvent& event) {}









// POST: Envia un mensaje cualquiera compuesto por dos bytes con
//       el tamanio y luego el contenido de msg. 
void Protocol::send_message(Socket& socket, const std::string& msg) const {
	uint16_t len = htons((uint16_t)msg.length());
	socket.send_message((char*)&len, 2);
	socket.send_message(msg.c_str(), msg.length());
}



// POST: Recibe un mensaje cualquiera compuesto por dos bytes
//       con el tamanio y luego el mensaje que se carga en msg.
void Protocol::recv_message(Socket& socket, std::string& msg) const {
	uint16_t len_msg;
	socket.recv_message((char*)&len_msg, 2);
	len_msg = ntohs(len_msg);
	if (len_msg == 0xffff)
		throw ExceptionInvalidCommand("Ocurrio un error de comandos.");
	std::vector<char> buf(len_msg+1);
	socket.recv_message(&buf[0], (unsigned)len_msg);
	buf[len_msg] = '\0';
	msg = &buf[0];
}






// PRE: La lista de partidas se puede escribir como string. 
// POST: Recibe la lista de partidas y la carga en el buffer.
void Protocol::get_list(Socket& socket, std::string& list) const {
	char list_byte = LIST_CODE;
	socket.send_message(&list_byte, 1);
	recv_message(socket, list);
}

// PRE: name es un string inicializado correctamente. 
// POST: Envia el mensaje para crear una partida con el nombre
//       name.  
void Protocol::send_create(Socket& socket, const std::string& name) const {
	char create_byte = CREATE_CODE;
	socket.send_message(&create_byte, 1);
	send_message(socket, name);
}


// POST: Retorna el tipo de mensaje que se recibira el cual puede ser
//       del tipo listar, crear, unirse o jugar. 
char Protocol::get_message_type(Socket& socket) const {
	char type;
	socket.recv_message(&type, 1);
	return type;
}

// PRE: name es un string inicializado correctamente. 
// POST: Envia el mensaje para unirse a una partida con el nombre
//       name. 
void Protocol::send_join(Socket& socket, const std::string& name) const {
	char join_byte = JOIN_CODE;
	socket.send_message(&join_byte, 1);
	send_message(socket, name);	
}





//POST: Envia dos bytes 0xffff indicando que ocurrio un error de
//      comando invalido. 
void Protocol::send_invalid_command_error(Socket& socket) const {
	uint16_t error_code = 0xffff;
	socket.send_message((char*)&error_code, 2);
}







Protocol::~Protocol() {}
