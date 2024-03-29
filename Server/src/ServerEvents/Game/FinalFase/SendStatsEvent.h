#ifndef _SEND_STATS_EVENT_H
#define _SEND_STATS_EVENT_H

#include "TypesOfEvents.h"
#include "Event.h"
#include <vector>
#include <string>
#include "Position.h"
#include "StepInformation.h"
#include "GameWorld.h"

class SendStatsEvent: public Event {
	public:
		SendStatsEvent(GameWorld& world, bool finished);
		~SendStatsEvent();
	private:
		SendStatsEvent(const SendStatsEvent &other) = delete;
		SendStatsEvent& operator=(const SendStatsEvent &other) = delete;
};

#endif
