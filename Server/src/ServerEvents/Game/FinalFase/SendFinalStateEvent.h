#ifndef _SEND_FINAL_STATE_EVENT_H
#define _SEND_FINAL_STATE_EVENT_H

#include "TypesOfEvents.h"
#include "Event.h"
#include <vector>
#include <string>
#include "Position.h"
#include "StepInformation.h"


class SendFinalStateEvent: public Event {
	public:
		SendFinalStateEvent(StepInformation& step);
		~SendFinalStateEvent();
	private:
		SendFinalStateEvent(const SendFinalStateEvent &other) = delete;
		SendFinalStateEvent& operator=(const SendFinalStateEvent &other) = delete;
};

#endif
