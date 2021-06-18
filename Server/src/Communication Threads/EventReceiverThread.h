#ifndef _EVENT_RECIEVER_THREAD_H
#define _EVENT_RECIEVER_THREAD_H

#include <string>
#include <atomic>
#include <syslog.h>

#include "ClientEvent.h"
#include "Thread.h"
#include "Socket.h"
#include "Exception.h"
#include "Protocol.h"
#include "ProtectedQueue.h"
#include "ClientEvent.h"

class EventReceiverThread: public Thread {
	int client_id;
	Socket& socket_recv;
	Protocol protocol;
	ProtectedQueue<ClientEvent>& events;
	std::atomic<bool> allowed_to_run;

	public:
		EventReceiverThread(Socket& skt, int id, ProtectedQueue<ClientEvent>& events);
		void stop_running();
		virtual void run() override;

		~EventReceiverThread();

	private:
		EventReceiverThread(const EventReceiverThread &other) = delete;
		EventReceiverThread& operator=(const EventReceiverThread &other) = delete;
};


#endif
