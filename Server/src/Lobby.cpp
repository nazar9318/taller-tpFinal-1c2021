#include "Lobby.h"

#include <iostream>
#include <syslog.h>
#include <string>
#include <utility>

Lobby::Lobby(Socket& skt, Matches& matches_counter):
							communication_skt(std::move(skt)),
							matches(matches_counter), finished(false) {
}
		

bool Lobby::is_finished() {
	return finished;
}


void Lobby::stop_running() {
	communication_skt.shutdown();
	finished = true;
}


void Lobby::run() {
	try {
		handle_lobby();
	} catch(std::exception &e) {
		syslog(LOG_CRIT, "[%s:%i]: %s", __FILE__, __LINE__, e.what());
	} catch(...) {
		syslog(LOG_CRIT, "[%s:%i]: Unknown error", __FILE__, __LINE__);
	}
	finished = true;
}


void Lobby::handle_lobby() {
	bool not_started = true;
	std::string match_name;
	while (not_started) {
		try {
			char type_msg = protocol.get_message_type(communication_skt);
			if (type_msg == LIST_CODE) {
				protocol.send_message(communication_skt, matches.get_names());
				continue;
			}
			if ((type_msg != CREATE_CODE) && (type_msg != JOIN_CODE)) 
				throw ExceptionInvalidCommand("Se recibió un comando inválido");
			protocol.recv_message(communication_skt, match_name);
			if (type_msg == CREATE_CODE) {
				GameWorldType world_type = (GameWorldType)protocol.get_message_type(communication_skt);
				matches.create(communication_skt, match_name, world_type);
			} else {
				matches.join_if_exists(communication_skt, match_name);
			}
			not_started = false;	
		} catch(ExceptionInvalidCommand &e) {
			syslog(LOG_CRIT, "[%s:%i]: %s", __FILE__, __LINE__, e.what()); 
			protocol.send_invalid_command_error(communication_skt);
        } catch(ExceptionMatchFull &e) {
			syslog(LOG_CRIT, "[%s:%i]: %s", __FILE__, __LINE__, e.what()); 
			protocol.send_invalid_command_error(communication_skt);
        }
    }
}

Lobby::~Lobby() {}