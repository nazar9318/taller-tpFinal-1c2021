#ifndef _MATCHES_H
#define _MATCHES_H

#include <string>
#include <map>
#include <mutex>
#include "Socket.h"
#include "Match.h"
#include "ExceptionInvalidCommand.h"
#include "Exception.h"
#include "GameWorld.h"

class Matches {
		std::map<std::string, Match*> matches;
		std::mutex m;
	
	public:
		Matches();
		
		// PRE: No hay ninguna partida con el nombre name. 
		// POST: Lanza un hilo al crear una partida y la agrega 
		//       a la estructura de partidas. 
		void create(Socket& skt, const std::string& name, const std::string map_type, 
			std::string player_name);

		// PRE: Existe ninguna partida con el nombre name. 
		// POST: Se une un jugador a la partida name.  
		void join_if_exists(Socket& skt, const std::string& name,
							 std::string player_name);

		// POST: Retorna los nombres de las partidas.  
		std::string get_matches_info();
		
		~Matches();
	
	private:
		void clear_matches();
		Matches(const Matches &other) = delete;
		Matches& operator=(const Matches &other) = delete;
};


#endif
