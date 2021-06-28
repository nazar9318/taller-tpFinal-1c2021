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

// POST: Finaliza la conexion cliente-servidor. 
void Lobby::stop_running() {
	communication_skt.shutdown();
	finished = true;
}

// POST: Inicia la comunicacion entre el cliente
//       y el servidor. Termina cuando ocurre un 
//       error o el cliente tiene asignada una 
//       partida.  
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

// Descripcion: implementa la logica del metodo run. 
void Lobby::handle_lobby() {
	bool not_started = true;
	std::string match_name;
	std::string user_name = get_user_name();
	while (not_started) {
		Event event = protocol.recv_event(communication_skt);
		switch (event.get_type()) {
			case ClientTypeEvent::GET_MAPS:
			{
				GetMapsHandler handler(communication_skt);
				handler.handle(event);
				break;
			}
			case ClientTypeEvent::GET_MATCHES:
			{
				GetMatchesHandler handler(communication_skt);
				handler.handle(event, matches);
				break;
			}
			case ClientTypeEvent::CREATE:
			{
				CreateMatchHandler handler(communication_skt);
				not_started = !handler.handle(event, matches, user_name);
				break;
			}
			case ClientTypeEvent::JOIN:
			{
				JoinMatchHandler handler(communication_skt);
				not_started = !handler.handle(event, matches, user_name);
				break;
			}
			default:
			{
				ErrorEvent error(ServerError::INVALID_TYPE_EVENT);
				protocol.send_event(communication_skt, error.get_msg());
			}
		}
	}
}

// Descripcion: manda un mensaje al cliente esperando
//              por un nombre de usuario y lo devuelve.
std::string Lobby::get_user_name() {
	Event event = protocol.recv_event(communication_skt);
	if (event.get_type() != ClientTypeEvent::USER_NAME)
		throw Exception("El primer mensaje de un cliente"
						" debe ser su nombre de usuario");
	std::string user_name(&(event.get_msg()[1]));
	syslog(LOG_INFO, "[%s:%i]: Cliente con nombre de"
					 " usurio %s entra al lobby."
					 , __FILE__, __LINE__, user_name.c_str());
	return user_name;
}

Lobby::~Lobby() {
}
