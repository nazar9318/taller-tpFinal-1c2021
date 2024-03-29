#include "CreateMatchHandler.h"
#include <syslog.h>
#include <string>

CreateMatchHandler::CreateMatchHandler(Socket& skt):
							 communication_skt(skt) {
}

// Descripcion: Crea una partida con las caracteristicas 
//              indicadas en event. 
// PRE: Event es del tipo CREATE.
// POST: retorna true si se creo una partida
//       de forma satisfactoria. 
bool CreateMatchHandler::handle(Event& event, Matches& matches,
							 const std::string& user_name) {
	if (event.get_type() != ClientTypeEvent::CREATE) {
		throw Exception("[%s:%i]: Se esperaba un"
				 "tipo Create", __FILE__, __LINE__);
	}
	// structure of event_msg: msg[0]: type,
	//                         msg[1], ..., msg[i] == \0: match_name 
	//                         msg[i], ..., msg[size-1] == \0: map_type 
	std::string match_name(&(event.get_msg()[START_CREATE_NAME]));
	std::string map_type(&(event.get_msg()[START_CREATE_NAME
						 + match_name.length() + 1]));
	syslog(LOG_INFO, "[%s:%i]: Se busca crear match con"
					 " nombre %s y mapa %s", __FILE__, __LINE__,
					  match_name.c_str(), map_type.c_str());
	try {
		matches.create(communication_skt, match_name, map_type, user_name);
		return true;
	} catch(ExceptionInvalidCommand &e) {
		syslog(LOG_CRIT, "[%s:%i]: %s", __FILE__, __LINE__, e.what()); 
		ErrorEvent error(e.get_type());
		protocol.send_event(communication_skt, error.get_msg());
	}
	return false;
}


CreateMatchHandler::~CreateMatchHandler() {
}
