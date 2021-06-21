#include "Server.h"

#include <syslog.h>
#include <string>

Server::Server(): listener(CF::port) {
	syslog(LOG_INFO, "Creando Server con parametro %s", CF::port.c_str());
}

// POST: Lee de stdin hasta recibir una 'q' indicando
//       que debe finalizar.
void Server::execute() {
	listener.start();
	bool server_active = true;
	while (server_active) {
		char msg;
		std::cin >> msg;
		if (msg == 'q') 
			server_active = false;
	}
	listener.stop_conection();
}

Server::~Server() {
}
