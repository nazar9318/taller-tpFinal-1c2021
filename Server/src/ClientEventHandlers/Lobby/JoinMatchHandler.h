#ifndef _JOIN_MATCH_HANDLER_H
#define _JOIN_MATCH_HANDLER_H

#include "TypesOfEvents.h"
#include "Event.h"
#include "Protocol.h"
#include "ErrorEvent.h"
#include "Matches.h"
#include "ExceptionMatchFull.h"


class JoinMatchHandler {
		Protocol protocol;
		Socket& communication_skt;

	public:
		JoinMatchHandler(Socket& skt);
		// returns true if join has success.
		bool handle(Event& event, Matches& matches, std::string user_name);
		~JoinMatchHandler();
	private:
		JoinMatchHandler(const JoinMatchHandler &other) = delete;
		JoinMatchHandler& operator=(const JoinMatchHandler &other) = delete;
};

#endif
