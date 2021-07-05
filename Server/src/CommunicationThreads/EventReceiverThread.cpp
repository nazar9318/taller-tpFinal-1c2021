#include "EventReceiverThread.h"

EventReceiverThread::EventReceiverThread(Socket& skt, char id,
			 	ProtectedQueue<Event>& queue, bool creator):
					client_id(id), socket_recv(skt), events(queue),
					allowed_to_run(true), is_creator(creator) {
	syslog(LOG_INFO, "[%s:%i]: Se crea un receiver"
			" con id %d", __FILE__, __LINE__, id);
}

// POST: Fuerza la finalizacion de la ejecucion de run()
void EventReceiverThread::stop_running() {
	socket_recv.shutdown(SHUT_RD);
	allowed_to_run = false;
}


// Descripcion: Recibe eventos a traves del procolo y los 
//              encola en la cola de enventos enviados por
//              el cliente. 
void EventReceiverThread::run() {
	try {
		while (allowed_to_run) {
			Event event = protocol.recv_event(socket_recv);
			event.add_client_id(client_id);
			events.push(event);
		}
	} catch(const ExceptionSocketClosed& e) {
		syslog(LOG_INFO, "[%s:%i]: Se cierra el socket del"
				" jugador con id %d. Msg:%s", __FILE__,
						 __LINE__, client_id, e.what());
		if (is_creator) {
			std::vector<char> error;
			error.push_back(ClientTypeEvent::CREATOR_ABANDONS);
			Event error_event(error, 1);
			events.push(error_event);
			syslog(LOG_ERR, "[%s:%i]: Pusheo el"
					" evento de error en el creador", __FILE__, __LINE__);
		}	
	} catch(const std::exception& e) {
		syslog(LOG_ERR, "[%s:%i]: Error: %s", __FILE__, __LINE__, e.what());
	} catch (...) {
		syslog(LOG_ERR, "[%s:%i]: Unknown Error", __FILE__, __LINE__);
	}
}

EventReceiverThread::~EventReceiverThread() {
	this->join();
	syslog(LOG_ERR, "[%s:%i]: Se hizo join de receiver"
					, __FILE__, __LINE__);
}
