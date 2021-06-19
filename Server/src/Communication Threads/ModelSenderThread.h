#ifndef _MODEL_SENDER_THREAD_H
#define _MODEL_SENDER_THREAD_H

#include <string>
#include <atomic>
#include <syslog.h>

#include "Event.h"
// #include "ModelEvent.h"
#include "ProtectedQueue.h"
#include "Thread.h"
#include "Socket.h"
#include "Exception.h"
#include "Protocol.h"

class ModelSenderThread: public Thread {
		Socket& socket_send;
		Protocol protocol;
		ProtectedQueue<std::shared_ptr<Event>>& events;
		std::atomic<bool> allowed_to_run;

	public:
		ModelSenderThread(Socket& skt,
		 ProtectedQueue<std::shared_ptr<Event>>& events);
		void stop_running();
		virtual void run() override;

		~ModelSenderThread();

	private:
		ModelSenderThread(const ModelSenderThread &other) = delete;
		ModelSenderThread& operator=(const ModelSenderThread &other) = delete;
};


#endif
