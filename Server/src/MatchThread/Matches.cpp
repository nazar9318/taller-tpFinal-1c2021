#include "Matches.h"

#include <list>
#include <syslog.h>
#include <string>

Matches::Matches() {
	syslog(LOG_INFO, "Creando Matches");
}

// PRE: No hay ninguna partida con el nombre name. 
// POST: Crea una partida y la agrega a la estructura
//       de partidas. 
void Matches::create(Socket& skt, const std::string& name,
		const std::string& map_type, const std::string& player_name) {
	std::lock_guard<std::mutex> l(m);
	if (matches.find(name) != matches.end()) {
		throw ExceptionInvalidCommand("La partida ya existe",
								 ServerError::MATCH_ALREADY_EXISTS);
	}
	syslog(LOG_INFO, "[%s:%i]: Por crear hilo match con mapa %s "
					 "y nombre de match %s", __FILE__, __LINE__,
					  map_type.c_str(), name.c_str());

	Match* match = new Match(skt, map_type, player_name);
	if (!match) {
		throw Exception("Error al alocar memoria para create de match");
	}
	match->start();
	matches[name] = match;
	clear_matches();
}

// PRE: Existe una partida con el nombre name. 
// POST: Se une un jugador a la partida name.  
void Matches::join_if_exists(Socket& skt,
		 const std::string& name, const std::string& player_name) {
	std::lock_guard<std::mutex> l(m);
	if (matches.find(name) == matches.end()) {
		syslog(LOG_CRIT, "[%s:%i]: No existe la partida %s"
					, __FILE__, __LINE__, name.c_str());
		throw ExceptionInvalidCommand("La partida no existe", 
			ServerError::MATCH_NOT_FOUND);
	}
	Match* match = matches.at(name);
	match->join_player_if_not_full(skt, player_name);
	clear_matches();
}

// POST: Retorna los nombres de las partidas.  
std::list<std::string> Matches::get_matches_info() {
	std::lock_guard<std::mutex> l(m);
	std::list<std::string> matches_names;
	for (auto it = matches.begin(); it != matches.end(); ++it) {
		matches_names.push_back(it->first);
	}
	return matches_names;
}

// POST: Elimina aquellas partidas que finalizaron.
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
		syslog(LOG_INFO, "[%s:%i]: Dejo de correr la partida"
					 , __FILE__, __LINE__);
		delete it->second;
	}
	syslog(LOG_INFO, "[%s:%i]: Se destruye matches"
					 , __FILE__, __LINE__);
}
