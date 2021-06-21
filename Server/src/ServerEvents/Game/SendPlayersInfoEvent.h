#ifndef _SEND_PLAYERS_INFO_EVENT_H
#define _SEND_PLAYERS_INFO_EVENT_H

#include "TypesOfEvents.h"
#include "Event.h"
#include <vector>
#include <string>


class SendPlayersInfoEvent: public Event {
	public:
		SendPlayersInfoEvent(std::vector<char> info);
		~SendPlayersInfoEvent();
	private:
		SendPlayersInfoEvent(const SendPlayersInfoEvent &other) = delete;
		SendPlayersInfoEvent& operator=(const SendPlayersInfoEvent &other) = delete;
};

#endif
