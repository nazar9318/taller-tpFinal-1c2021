#ifndef _SERVER_H
#define _SERVER_H

#include <iostream>
#include "Listener.h"
#include "Configuration.h"

class Server {
	Listener listener;

	public:
		Server();

		// POST: Lee de stdin hasta recibir una 'q' indicando
		//       que debe finalizar.
		void execute();

		~Server();

	private:
		Server(const Server &other) = delete;
		Server& operator=(const Server &other) = delete;
};

#endif
