#ifndef _MATCHES_H
#define _MATCHES_H

#include <string>
#include <map>
#include <mutex>
#include <list>
#include "Socket.h"
#include "Match.h"
#include "ExceptionInvalidCommand.h"
#include "Exception.h"
#include "GameWorld.h"
#include "TypesOfEvents.h"

class Matches {
		// (game_name, Match*)
		std::map<std::string, Match*> matches;
		std::mutex m;
	
	public:
		Matches();
		
		// PRE: No hay ninguna partida con el nombre name. 
		// POST: Lanza un hilo al crear una partida y la agrega 
		//       a la estructura de partidas. 
		void create(Socket& skt, const std::string& name,
		 	const std::string& map_type, const std::string& player_name);

		// PRE: Existe una partida con el nombre name. 
		// POST: Se une un jugador a la partida name.  
		void join_if_exists(Socket& skt, const std::string& name,
							 const std::string& player_name);

		// POST: Retorna los nombres de las partidas.  
		std::list<std::string> get_matches_info();
		
		~Matches();
	
	private:
		// POST: Elimina aquellas partidas que finalizaron. 
		void clear_matches();

		Matches(const Matches &other) = delete;
		Matches& operator=(const Matches &other) = delete;
};

#endif
