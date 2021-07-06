#ifndef _SEND_INIT_PLAYERS_EVENT_H
#define _SEND_INIT_PLAYERS_EVENT_H

#include "TypesOfEvents.h"
#include "Event.h"
#include <vector>
#include <string>
#include "Position.h"
#include "StepInformation.h"


class SendInitPlayersEvent: public Event {
	public:
		SendInitPlayersEvent(StepInformation& step);
		~SendInitPlayersEvent();
	private:
		SendInitPlayersEvent(const SendInitPlayersEvent &other) = delete;
		SendInitPlayersEvent& operator=(const SendInitPlayersEvent &other) = delete;
};

#endif
