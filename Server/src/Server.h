#ifndef _SERVER_H
#define _SERVER_H

#include <iostream>
#include <string>
#include "Socket.h"
#include "Listener.h"

class Server {
	Listener listener;

	public:
		explicit Server(const std::string& port);

		// POST: Lee de stdin hasta recibir una 'q' indicando
		//       que debe finalizar.
		void excecute();

		~Server();

	private:
		Server(const Server &other) = delete;
		Server& operator=(const Server &other) = delete;
};

#endif
