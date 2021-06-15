#include "Server.h"

#include <iostream>
#include <syslog.h>
#include <string>

Server::Server(const std::string& port) /*listener(port)*/ {
	syslog(LOG_INFO, "Creando Server con parametro %s", port.c_str());
}

// POST: Lee de stdin hasta recibir una 'q' indicando
//       que debe finalizar.
void Server::excecute() {
	/*
	listener.start();
	bool server_active = true;
	while (server_active) {
		char msg;
		std::cin >> msg;
		if (msg == 'q') 
			server_active = false;
	}
	listener.stop_conection();
	*/
}

Server::~Server() {
}
