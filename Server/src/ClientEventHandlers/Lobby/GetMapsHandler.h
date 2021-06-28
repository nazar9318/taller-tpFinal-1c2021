#ifndef _GET_MAPS_HANDLER_H
#define _GET_MAPS_HANDLER_H

#include "TypesOfEvents.h"
#include "Event.h"
#include "Protocol.h"
#include "SendMapsEvent.h"
#include "MapParser.h"

class GetMapsHandler {
		Protocol protocol;
		Socket& communication_skt;

	public:
		GetMapsHandler(Socket& skt);
		
		// PRE: El evento es del tipo GET_MAPS.
		// POST: Devuelve por el protocolo los mapas. 
		void handle(Event& event);
		~GetMapsHandler();
	private:
		GetMapsHandler(const GetMapsHandler &other) = delete;
		GetMapsHandler& operator=(const GetMapsHandler &other) = delete;
};

#endif
