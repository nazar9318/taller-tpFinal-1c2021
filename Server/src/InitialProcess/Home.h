#ifndef _HOME_H
#define _HOME_H

#include <iostream>
#include <string>
#include <syslog.h>
#include <unordered_set>
#include "Socket.h"
#include "Matches.h"
#include "Lobby.h"


class Home {
	std::unordered_set<Lobby*> clients_in_lobby;
	Matches matches;
	public:
		Home();

		// PRE: El socket esta correctamente inicializado. 
		void add_client(Socket skt_client);
		
		~Home();

	private:
		// POST: Libera los recursos de los hilos que ya finalizaron su
		//       ejecucion.
		void clear_clients();
		Home(const Home &other) = delete;
		Home& operator=(const Home &other) = delete;
};

#endif
