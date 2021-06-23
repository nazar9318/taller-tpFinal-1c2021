#ifndef _JOIN_MATCH_EVENT_H
#define _JOIN_MATCH_EVENT_H

#include "TypesOfEvents.h"
#include "Event.h"
#include <string>


class JoinMatchEvent: public Event {
	public:
		JoinMatchEvent(std::string match_name);
		~JoinMatchEvent();
	private:
		JoinMatchEvent(const JoinMatchEvent &other) = delete;
		JoinMatchEvent& operator=(const JoinMatchEvent &other) = delete;
};

#endif
