#ifndef _GET_MATCHES_HANDLER_H
#define _GET_MATCHES_HANDLER_H

#include "TypesOfEvents.h"
#include "Event.h"
#include "Protocol.h"
#include "SendMatchesEvent.h"
#include "Matches.h"

class GetMatchesHandler {
		Protocol protocol;
		Socket& communication_skt;

	public:
		GetMatchesHandler(Socket& skt);
		
		// PRE: El evento es del tipo GET_MATCHES.
		// POST: Devuelve por el protocolo los matches. 
		void handle(Event& event, Matches& matches);
		~GetMatchesHandler();

	private:
		GetMatchesHandler(const GetMatchesHandler &other) = delete;
		GetMatchesHandler& operator=(const GetMatchesHandler &other) = delete;
};

#endif
