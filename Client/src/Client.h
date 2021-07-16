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
	public:
		Client();

		// POST: Executes the Counter Strike game.
		void execute(int argc, char** argv);

		~Client();

	private:
		Client(const Client &other) = delete;
		Client& operator=(const Client &other) = delete;
};


#endif
