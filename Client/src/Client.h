#ifndef _CLIENT_H
#define _CLIENT_H

#include <string>
#include <iostream>
#include <syslog.h>
#include <map>

#include "Event.h"
#include "Exception.h"
#include "ProtectedQueue.h"
#include "EventSenderThread.h"
#include "ModelRecieverThread.h"
#include "Initiator.h"
#include "Game.h"

class Client {
	Socket socket;
	ProtectedQueue<Event> model_events;
	ProtectedQueue<std::unique_ptr<Event>> client_events;
	ModelRecieverThread reciever;
	EventSenderThread sender;
	std::map<char, std::string> players;

	public:
		Client(const std::string& host, const std::string& port);

		// POST: Executes the Counter Strike game.
		void execute(int argc, char** argv);

		~Client();

	private:
		Client(const Client &other) = delete;
		Client& operator=(const Client &other) = delete;
};


#endif
