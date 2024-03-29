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
	bool& active;
	std::string& port;
	std::string& host;

	public:
		Initiator(ModelRecieverThread& receiver, EventSenderThread& sender,
		 ProtectedQueue<Event>& model_events,
		  ProtectedQueue<std::unique_ptr<Event>>& client_events, bool& active,
		std::string& port, std::string& host);

		// returns true if player is logged in.
		void launch(Socket& socket, int argc, char** argv, bool &game_started,
						std::map<char, std::string>& players, char& self_id,
						bool& user_name_charged, std::string& name);
		~Initiator();

	private:
		Initiator(const Initiator &other) = delete;
		Initiator& operator=(const Initiator &other) = delete;
};


#endif
