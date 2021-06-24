#ifndef _LOBBY_H
#define _LOBBY_H

#include <iostream>
#include <string>
#include "Socket.h"
#include "Thread.h"
#include "Protocol.h"
#include "Matches.h"
#include "ExceptionInvalidCommand.h"
#include "ExceptionMatchFull.h"
#include "TypesOfEvents.h"
#include "GetMapsHandler.h"
#include "GetMatchesHandler.h"
#include "CreateMatchHandler.h"
#include "JoinMatchHandler.h"
#include "ErrorEvent.h"


class Lobby: public Thread {
		Protocol protocol;
		Socket communication_skt;
		Matches& matches;
		std::atomic<bool> finished;

	public:
		Lobby(Socket& skt, Matches& matches);
		bool is_finished();
		void stop_running();
		virtual void run() override;
		~Lobby();

	private:
		void handle_lobby();
		std::string get_user_name();
		Lobby(const Lobby &other) = delete;
		Lobby& operator=(const Lobby &other) = delete;
};

#endif
