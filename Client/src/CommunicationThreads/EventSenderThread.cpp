#include "EventSenderThread.h"



EventSenderThread::EventSenderThread(Socket& skt,
					ProtectedQueue<ClientEvent>& queue):
					socket_send(skt), events(queue), 
					allowed_to_run(true) {}

void EventSenderThread::stop_running() {
	socket_send.shutdown(SHUT_WR);
	allowed_to_run = false;

}

void EventSenderThread::run() {
	try {
		while (allowed_to_run) {
			/*ClientEvent event;
			events.blocking_pop(event);*/
			ClientEvent& event = events.blocking_pop();
			protocol.send_msg(socket_send, event.type(), event.to_string());
		}
	} catch(const std::exception& e) {
		syslog(LOG_ERR, "[%s:%i]: Error: %s", __FILE__, __LINE__, e.what());
	} catch (...) {
		syslog(LOG_ERR, "[%s:%i]: Unknown Error", __FILE__, __LINE__);
	}
}

EventSenderThread::~EventSenderThread() {
	this->join();
}