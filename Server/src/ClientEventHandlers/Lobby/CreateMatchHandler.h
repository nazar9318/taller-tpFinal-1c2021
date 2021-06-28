#ifndef _CREATE_MATCH_HANDLER_H
#define _CREATE_MATCH_HANDLER_H

#include <string>
#include "TypesOfEvents.h"
#include "Event.h"
#include "Protocol.h"
#include "ErrorEvent.h"
#include "Matches.h"

class CreateMatchHandler {
		Protocol protocol;
		Socket& communication_skt;

	public:
		explicit CreateMatchHandler(Socket& skt);

		// Descripcion: Crea una partida con las caracteristicas 
		//              indicadas en event. 
		// PRE: Event es del tipo CREATE.
		// POST: retorna true si se creo una partida
		//       de forma satisfactoria. 
		bool handle(Event& event, Matches& matches,
						 const std::string& user_name);

		~CreateMatchHandler();
	private:
		CreateMatchHandler(const CreateMatchHandler &other) = delete;
		CreateMatchHandler& operator=(const CreateMatchHandler &other) = delete;
};

#endif
