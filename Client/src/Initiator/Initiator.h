#ifndef _INITIATOR_H
#define _INITIATOR_H

#include <string>
#include <iostream>
#include <map>
#include "Socket.h"
#include "Protocol.h"
#include "Parser.h"
#include "ProtectedQueue.h"
#include "ModelRecieverThread.h"
#include "EventSenderThread.h"

#include <QApplication>
#include "mainwindow.h"


#include "StartGameEvent.h"

class Initiator {
	ModelRecieverThread& receiver;
	EventSenderThread& sender;
	ProtectedQueue<Event>& model_events;
	ProtectedQueue<std::unique_ptr<Event>>& client_events;

	public:
		Initiator(ModelRecieverThread& receiver, EventSenderThread& sender,
		 ProtectedQueue<Event>& model_events, ProtectedQueue<std::unique_ptr<Event>>& client_events);

		// returns true if player is logged in.
		void launch(Socket& socket, int argc, char** argv, bool &game_started,
						std::map<char, PlayerInformation>& players);
		~Initiator();

	private:
		Initiator(const Initiator &other) = delete;
		Initiator& operator=(const Initiator &other) = delete;
};


#endif
