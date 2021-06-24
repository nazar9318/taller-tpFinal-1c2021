#ifndef _CREATE_MATCH_HANDLER_H
#define _CREATE_MATCH_HANDLER_H

#include "TypesOfEvents.h"
#include "Event.h"
#include "Protocol.h"
#include "ErrorEvent.h"
#include "Matches.h"

class CreateMatchHandler {
		Protocol protocol;
		Socket& communication_skt;

	public:
		CreateMatchHandler(Socket& skt);
		// returns true if create has success.
		bool handle(Event& event, Matches& matches, std::string user_name);
		~CreateMatchHandler();
	private:
		CreateMatchHandler(const CreateMatchHandler &other) = delete;
		CreateMatchHandler& operator=(const CreateMatchHandler &other) = delete;
};

#endif
