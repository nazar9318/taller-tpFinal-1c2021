#include "EventSenderThread.h"



EventSenderThread::EventSenderThread(Socket& skt, ProtectedQueue<std::unique_ptr<Event>>& queue):
					socket_send(skt), events(queue),
					allowed_to_run(true) {}

void EventSenderThread::stop_running() {
	socket_send.shutdown(SHUT_WR);
	events.close();
	allowed_to_run = false;
}

void EventSenderThread::run() {
	try {
		while (allowed_to_run) {
			std::unique_ptr<Event> event = events.blocking_pop();
			protocol.send_event(socket_send, event->get_msg());
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
