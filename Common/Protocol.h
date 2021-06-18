#ifndef _PROTOCOL_H
#define _PROTOCOL_H

#include <string>
#include "Socket.h"
#include "ModelEvent.h"
#include "ClientEvent.h"
#include "Exception.h"
#include "ExceptionInvalidCommand.h"
#include <memory>
#define LIST_CODE 0x6C
#define CREATE_CODE 0x6e
#define PLAY_CODE 0x70
#define JOIN_CODE 0x6a
#define ERROR_CODE 0xff
#define INVALID_NAME 0
#define INVALID_CODE 1


class Protocol {
	public:
		Protocol();

		// PRE: La lista de partidas se puede escribir como string. 
		// POST: Recibe la lista de partidas y la carga en el buffer.
		void get_list(Socket& socket, std::string& buffer) const;

		// PRE: name es un string inicializado correctamente. 
		// POST: Envia el mensaje para crear una partida con el nombre
		//       name.  
		void send_create(Socket& socket, const std::string& name) const;
	
		// PRE: name es un string inicializado correctamente. 
		// POST: Envia el mensaje para unirse a una partida con el nombre
		//       name. 
		void send_join(Socket& socket, const std::string& name) const;


		// POST: Retorna el tipo de mensaje que se recibira el cual puede ser
		//       del tipo listar, crear, unirse o jugar. 
		char get_message_type(Socket& socket) const;

		//POST: Envia dos bytes 0xffff indicando que ocurrio un error de
		//      comando invalido. 
		void send_invalid_command_error(Socket& socket) const;

				// POST: Envia un mensaje cualquiera compuesto por dos bytes con
		//       el tamanio y luego el contenido de msg. 
		void send_message(Socket& socket, const std::string& msg) const;




		// POST: Recibe un mensaje cualquiera compuesto por dos bytes
		//       con el tamanio y luego el mensaje que se carga en msg.
		void recv_message(Socket& socket, std::string& msg) const;







		void recv_event(Socket& socket, ModelEvent& event);
		void recv_event(Socket& socket, ClientEvent& event);
		
		void send_event(Socket& socket, std::shared_ptr<ModelEvent> event);
		void send_event(Socket& socket, ClientEvent& event);



		// POST: Recibe un mensaje cualquiera compuesto por dos bytes
		//       con el tamanio y luego el mensaje que se carga en msg.
		void recv_message(Socket& socket, char type, std::string& msg) const;
		

		// POST: Envia un mensaje cualquiera compuesto por dos bytes con
		//       el tamanio y luego el contenido de msg. 
		void send_msg(Socket& socket, char type, const std::string& msg) const;

		~Protocol();

	private:
		Protocol(const Protocol &other) = delete;
		Protocol& operator=(const Protocol &other) = delete;
};

#endif
