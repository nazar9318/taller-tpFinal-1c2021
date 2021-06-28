#ifndef _MODEL_SENDER_THREAD_H
#define _MODEL_SENDER_THREAD_H

#include <string>
#include <atomic>
#include <syslog.h>

#include "Event.h"
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
		
		// POST: Fuerza la finalizacion de la ejecucion de run()
		void stop_running();

		// Descripcion: Desencola de la cola bloqueante y envia el 
		//              evento correspondiente a traves del protocolo. 
		virtual void run() override;

		~ModelSenderThread();

	private:
		ModelSenderThread(const ModelSenderThread &other) = delete;
		ModelSenderThread& operator=(const ModelSenderThread &other) = delete;
};


#endif
