#ifndef _MODEL_RECIEVER_THREAD_H
#define _MODEL_RECIEVER_THREAD_H

#include <string>
#include <atomic>
#include <syslog.h>

#include "ModelEvent.h"
#include "Thread.h"
#include "Socket.h"
#include "Exception.h"
#include "Protocol.h"
#include "ProtectedQueue.h"
#include "ModelEvent.h"

class ModelRecieverThread: public Thread {
	Socket& socket_recv;
	Protocol protocol;
	ProtectedQueue<Event>& events;
	std::atomic<bool> allowed_to_run;

	public:
		ModelRecieverThread(Socket& skt, ProtectedQueue<Event>& events);
		void stop_running();
		virtual void run() override;

		~ModelRecieverThread();

	private:
		ModelRecieverThread(const ModelRecieverThread &other) = delete;
		ModelRecieverThread& operator=(const ModelRecieverThread &other) = delete;
};


#endif
