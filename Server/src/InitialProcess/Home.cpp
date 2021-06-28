#include "Home.h"


Home::Home() {
}


// PRE: El socket esta correctamente inicializado. 
// POST: Crea y lanza un hilo nuevo y lo agrega a la estructura
//       de clientes en lobby. 
void Home::add_client(Socket skt_client) {
	Lobby* client_lobby = new Lobby(skt_client, matches);
	if (!client_lobby) 
		throw Exception("[%s:%i]: No se pudo hacer new de client_lobby",
		 				__FILE__, __LINE__);
	syslog(LOG_INFO, "Por hacer el run del client.");
	client_lobby->start();
	clients_in_lobby.insert(client_lobby);
	clear_clients();
}

// POST: Libera los recursos de los hilos que ya finalizaron su
//       ejecucion
void Home::clear_clients() {
	std::unordered_set<Lobby*> threads_cleaned;
	for (auto it = clients_in_lobby.begin(); it != clients_in_lobby.end(); ++it) {
		if ((*it)->is_finished()) {
			(*it)->join();
			delete *it;
		} else {
			threads_cleaned.insert(*it);
		}
	}
	clients_in_lobby.swap(threads_cleaned);
}


Home::~Home() {
	for (auto it = clients_in_lobby.begin(); it != clients_in_lobby.end(); ++it) {
		(*it)->stop_running();
		(*it)->join();
		delete *it;
  	}
	syslog(LOG_INFO, "Se elimina Home");
}
