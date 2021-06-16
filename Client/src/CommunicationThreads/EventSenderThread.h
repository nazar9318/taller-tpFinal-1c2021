#ifndef _EVENT_SENDER_THREAD_H
#define _EVENT_SENDER_THREAD_H

#include <string>
#include <atomic>
#include <syslog.h>

#include "ClientEvent.h"
#include "ProtectedQueue.h"
#include "Thread.h"
#include "Socket.h"
#include "Exception.h"
#include "Protocol.h"

class EventSenderThread: public Thread {
		Socket& socket_send;
		Protocol protocol;
		ProtectedQueue<ClientEvent>& events;
		std::atomic<bool> allowed_to_run;

	public:
		EventSenderThread(Socket& skt, ProtectedQueue<ClientEvent>& events);
		void stop_running();
		virtual void run() override;

		~EventSenderThread();

	private:
		EventSenderThread(const EventSenderThread &other) = delete;
		EventSenderThread& operator=(const EventSenderThread &other) = delete;
};


#endif
