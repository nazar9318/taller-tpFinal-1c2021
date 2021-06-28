#ifndef _JOIN_MATCH_HANDLER_H
#define _JOIN_MATCH_HANDLER_H

#include <string>
#include "TypesOfEvents.h"
#include "Event.h"
#include "Protocol.h"
#include "ErrorEvent.h"
#include "Matches.h"

class JoinMatchHandler {
		Protocol protocol;
		Socket& communication_skt;

	public:
		explicit JoinMatchHandler(Socket& skt);
		
		// Descripcion: Se une a  una partida con las  
		//              caracteristicas indicadas en event. 
		// PRE: Event es del tipo JOIN.
		// POST: retorna true si se unio a una partida
		//       de forma satisfactoria. 
		bool handle(Event& event, Matches& matches, 
					const std::string& user_name);
		
		~JoinMatchHandler();
	private:
		JoinMatchHandler(const JoinMatchHandler &other) = delete;
		JoinMatchHandler& operator=(const JoinMatchHandler &other) = delete;
};

#endif
