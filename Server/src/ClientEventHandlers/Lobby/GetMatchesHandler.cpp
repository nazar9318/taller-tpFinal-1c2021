#include "GetMatchesHandler.h"

GetMatchesHandler::GetMatchesHandler(Socket& skt): communication_skt(skt) {
}

void GetMatchesHandler::handle(Event& event, Matches& matches) {
	if (event.get_type() != ClientTypeEvent::GET_MATCHES) {
		throw Exception("[%s:%i]: Se esperaba un"
				 "tipo GetMatches", __FILE__, __LINE__);
	}
	// clientGetMatchesEvent doesn't contain any msg. 
	SendMatchesEvent srv_event(matches.get_matches_info());
	protocol.send_event(communication_skt, srv_event.get_msg());
}


GetMatchesHandler::~GetMatchesHandler() {}