#ifndef _SEND_BUYS_EVENT_H
#define _SEND_BUYS_EVENT_H

#include "TypesOfEvents.h"
#include "Event.h"
#include <vector>
#include <string>
#include "Position.h"
#include "StepInformation.h"



class SendBuysEvent: public Event {
	public:
		SendBuysEvent(StepInformation& step);
		~SendBuysEvent();
	private:
		SendBuysEvent(const SendBuysEvent &other) = delete;
		SendBuysEvent& operator=(const SendBuysEvent &other) = delete;
};

#endif
