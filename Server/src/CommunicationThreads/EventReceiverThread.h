#ifndef _EVENT_RECIEVER_THREAD_H
#define _EVENT_RECIEVER_THREAD_H

#include <string>
#include <atomic>
#include <syslog.h>

#include "ExceptionSocketClosed.h"
#include "Thread.h"
#include "Socket.h"
#include "Exception.h"
#include "Protocol.h"
#include "ProtectedQueue.h"
#include "Event.h"

class EventReceiverThread: public Thread {
	char client_id;
	Socket& socket_recv;
	Protocol protocol;
	ProtectedQueue<Event>& events;
	std::atomic<bool> allowed_to_run;

	public:
		EventReceiverThread(Socket& skt, char id,
						 ProtectedQueue<Event>& events);
		
		// POST: Fuerza la finalizacion de la ejecucion de run()
		void stop_running();

		// Descripcion: Recibe eventos a traves del procolo y los 
		//              encola en la cola de enventos enviados por
		//              el cliente.  	
		virtual void run() override;

		~EventReceiverThread();

	private:
		EventReceiverThread(const EventReceiverThread &other) = delete;
		EventReceiverThread& operator=(const EventReceiverThread &other) = delete;
};


#endif
