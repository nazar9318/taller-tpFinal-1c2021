#include "JoinMatchHandler.h"
#include <syslog.h>

JoinMatchHandler::JoinMatchHandler(Socket& skt):
						 communication_skt(skt) {
}

// Descripcion: Se une a  una partida con las  
//              caracteristicas indicadas en event. 
// PRE: Event es del tipo JOIN.
// POST: retorna true si se unio a una partida
//       de forma satisfactoria. 
bool JoinMatchHandler::handle(Event& event, Matches& matches,
							 const std::string& user_name) {
	if (event.get_type() != ClientTypeEvent::JOIN) {
		throw Exception("[%s:%i]: Se esperaba un"
				 "tipo Join", __FILE__, __LINE__);
	}
	// structure of join_msg: msg[0]: type,
	//                        msg[1], ..., msg[size-1] == \0: match_name 
	std::string match_name(&event.get_msg()[START_JOIN_NAME]);
	syslog(LOG_INFO, "[%s:%i]: Se busca unirse a match con"
					 " nombre %s", __FILE__, __LINE__,
					  match_name.c_str());
	try {
		matches.join_if_exists(communication_skt, match_name, user_name);
		return true;
	} catch(ExceptionInvalidCommand &e) {
		syslog(LOG_CRIT, "[%s:%i]: %s", __FILE__, __LINE__, e.what()); 
		ErrorEvent error(e.get_type());
		protocol.send_event(communication_skt, error.get_msg());
	} 
	return false;
}

JoinMatchHandler::~JoinMatchHandler() {
}
