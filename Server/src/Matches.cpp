#include "Matches.h"

#include <syslog.h>
#include <string>

Matches::Matches() {
	syslog(LOG_INFO, "Creando Matches");
}

// PRE: No hay ninguna partida con el nombre name. 
// POST: Crea una partida y la agrega a la estructura
//       de partidas. 
void Matches::create(Socket& skt, const std::string& name, GameWorldType type) {
	std::lock_guard<std::mutex> l(m);
	if (matches.find(name) != matches.end())
		throw ExceptionInvalidCommand("La partida ya existe");
	Match* match = new Match(skt, type);
	if (!match) {
		throw Exception("Error al alocar memoria para create de match");
	}
	match->start();
	matches[name] = match;
	clear_matches();
}

// PRE: Existe ninguna partida con el nombre name. 
// POST: Se une un jugador a la partida name.  
void Matches::join_if_exists(Socket& skt, const std::string& name) {
	std::lock_guard<std::mutex> l(m);
	if (matches.find(name) == matches.end())
		throw ExceptionInvalidCommand("La partida no existe");
	Match* match = matches.at(name);
	match->join_player_if_not_full(skt);
	clear_matches();
}

// POST: Retorna los nombres de las partidas.  
std::string Matches::get_names() {
	std::lock_guard<std::mutex> l(m);
	std::string list;
	for (auto it = matches.begin(); it != matches.end(); ++it) {
		list += it->first;
		list += ";";
	}
	return list;
}


void Matches::clear_matches() {
	for (auto it = matches.begin(); it != matches.end(); ++it) {
		if (it->second->is_finished()) {
			it->second->join();
			delete it->second;
			matches.erase(it->first);
		}
	}
}

Matches::~Matches() {
	for (auto it = matches.begin(); it != matches.end(); ++it) {
		it->second->stop_running();
		it->second->join();
		delete it->second;
	}
}
