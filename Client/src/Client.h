#ifndef _CLIENT_H
#define _CLIENT_H

#include <string>
#include <iostream>
#include <syslog.h>

#include "ClientEvent.h"
#include "ModelEvent.h"
#include "ProtectedQueue.h"
#include "EventSenderThread.h"
#include "ModelRecieverThread.h"
#include "GameMap.h"
#include "Initiator.h"
#include "Game.h"

class Client {
	Socket socket; 
	ProtectedQueue<ModelEvent> model_events;
	ProtectedQueue<ClientEvent> client_events;
	ModelRecieverThread reciever;
	EventSenderThread sender;
	
	public:
		Client(const std::string& host, const std::string& port);
		
		// POST: Executes the Counter Strike game.  
		void execute();

		~Client();

	private:
		Client(const Client &other) = delete;
		Client& operator=(const Client &other) = delete;
};


#endif

