#include "GetMapsHandler.h"

GetMapsHandler::GetMapsHandler(Socket& skt):
					 communication_skt(skt) {
}

// PRE: El evento es del tipo GET_MAPS.
// POST: Devuelve por el protocolo los mapas. 
void GetMapsHandler::handle(Event& event) {
	if (event.get_type() != ClientTypeEvent::GET_MAPS) {
		throw Exception("[%s:%i]: Se esperaba un"
				 "tipo GetMaps", __FILE__, __LINE__);
	}
	// clientGetMapsEvent doesn't contain any msg. 
	
	MapParser parser;
	SendMapsEvent srv_event(parser.get_maps());
	protocol.send_event(communication_skt, srv_event.get_msg());
}


GetMapsHandler::~GetMapsHandler() {
}
