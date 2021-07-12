#include "ModelRecieverThread.h"
#include <queue>
ModelRecieverThread::ModelRecieverThread(Socket& skt, ProtectedQueue<Event>& queue):
					socket_recv(skt), events(queue),
					allowed_to_run(true) {}

void ModelRecieverThread::stop_running() {
	socket_recv.shutdown(SHUT_RD);
	allowed_to_run = false;
}

void ModelRecieverThread::run() {
	try {
		while (allowed_to_run) {
			Event event = protocol.recv_event(socket_recv);
			// syslog(LOG_ERR, "[%s:%i]: Recibo event: %d"
			// 			, __FILE__, __LINE__,event.get_type());

			events.push(event);
		}
	} catch(const std::exception& e) {
		syslog(LOG_ERR, "[%s:%i]: Error: %s", __FILE__, __LINE__, e.what());
	} catch (...) {
		syslog(LOG_ERR, "[%s:%i]: Unknown Error", __FILE__, __LINE__);
	}
}

ModelRecieverThread::~ModelRecieverThread() {
	if (this->joinable()) {
		this->join();
	}
}
