#include "ModelSenderThread.h"



ModelSenderThread::ModelSenderThread(Socket& skt,
					ProtectedQueue<std::shared_ptr<ModelEvent>>& queue):
					socket_send(skt), events(queue), 
					allowed_to_run(true) {}

void ModelSenderThread::stop_running() {
	socket_send.shutdown(SHUT_WR);
	allowed_to_run = false;

}

void ModelSenderThread::run() {
	try {
		while (allowed_to_run) {
			std::shared_ptr<ModelEvent> event = events.blocking_pop();
			protocol.send_event(socket_send, event);
		}
	} catch(const std::exception& e) {
		syslog(LOG_ERR, "[%s:%i]: Error: %s", __FILE__, __LINE__, e.what());
	} catch (...) {
		syslog(LOG_ERR, "[%s:%i]: Unknown Error", __FILE__, __LINE__);
	}
}

ModelSenderThread::~ModelSenderThread() {
	this->join();
}