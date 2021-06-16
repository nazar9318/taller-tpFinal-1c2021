#ifndef _PROTOCOL_H
#define _PROTOCOL_H

#include <string>
#include "Socket.h"
#include "ModelEvent.h"

class Protocol {
	public:
		Protocol();

		void recv_event(Socket& socket, ModelEvent& event);


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
