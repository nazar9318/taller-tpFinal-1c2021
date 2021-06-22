#include "EventReceiverThread.h"
#include <queue>

EventReceiverThread::EventReceiverThread(Socket& skt,
					int id, ProtectedQueue<Event>& queue):
					client_id(id), socket_recv(skt), events(queue),
					allowed_to_run(true) {}

void EventReceiverThread::stop_running() {
	socket_recv.shutdown(SHUT_RD);
	allowed_to_run = false;
}


void EventReceiverThread::run() {
	try {
		while (allowed_to_run) {
			Event event = protocol.recv_event(socket_recv);
			event.add_client_id(client_id);
			events.push(event);
		}
	} catch(const std::exception& e) {
		syslog(LOG_ERR, "[%s:%i]: Error: %s", __FILE__, __LINE__, e.what());
	} catch (...) {
		syslog(LOG_ERR, "[%s:%i]: Unknown Error", __FILE__, __LINE__);
	}
}

EventReceiverThread::~EventReceiverThread() {
	this->join();
}
