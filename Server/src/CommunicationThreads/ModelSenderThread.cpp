#include "ModelSenderThread.h"

ModelSenderThread::ModelSenderThread(Socket& skt,
					ProtectedQueue<std::shared_ptr<Event>>& queue):
					socket_send(skt), events(queue),
					allowed_to_run(true) {
	syslog(LOG_INFO, "[%s:%i]: Se crea un sender"
					, __FILE__, __LINE__);
}

// POST: Fuerza la finalizacion de la ejecucion de run().
void ModelSenderThread::stop_running() {
	socket_send.shutdown(SHUT_WR);
	allowed_to_run = false;
	events.close();
}

// Descripcion: Desencola de la cola bloqueante y envia el
//              evento correspondiente a traves del protocolo.
void ModelSenderThread::run() {
	try {
		while (allowed_to_run) {
			std::shared_ptr<Event> event = events.blocking_pop();
			// syslog(LOG_ERR, "[%s:%i]: Envio event: %d"
			// 		, __FILE__, __LINE__,event->get_type());

			protocol.send_event(socket_send, event->get_msg());
		}
	} catch(const std::exception& e) {
		syslog(LOG_ERR, "[%s:%i]: Error: %s", __FILE__, __LINE__, e.what());
	} catch (...) {
		syslog(LOG_ERR, "[%s:%i]: Unknown Error", __FILE__, __LINE__);
	}
	events.close();
}

ModelSenderThread::~ModelSenderThread() {
	this->join();
	syslog(LOG_INFO, "[%s:%i]: Se hizo join de sender"
						, __FILE__, __LINE__);
}
