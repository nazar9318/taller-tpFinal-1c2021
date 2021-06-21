#include "JoinMatchHandler.h"
#include <syslog.h>

JoinMatchHandler::JoinMatchHandler(Socket& skt): communication_skt(skt) {
}

// returns true if create has success.
bool JoinMatchHandler::handle(Event& event, Matches& matches) {
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
		matches.join_if_exists(communication_skt, match_name);
		return true;
	} catch(ExceptionInvalidCommand &e) {
		syslog(LOG_CRIT, "[%s:%i]: %s", __FILE__, __LINE__, e.what()); 
		ErrorEvent error(ServerError::INVALID_COMMAND);
		protocol.send_event(communication_skt, error.get_msg());
	} catch(ExceptionMatchFull &e) {
		syslog(LOG_CRIT, "[%s:%i]: %s", __FILE__, __LINE__, e.what()); 
		ErrorEvent error(ServerError::MATCH_FULL);
		protocol.send_event(communication_skt, error.get_msg());
	}
	return false;
}

JoinMatchHandler::~JoinMatchHandler() {}
