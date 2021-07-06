#ifndef _SEND_ATTACKS_INFO_EVENT_H
#define _SEND_ATTACKS_INFO_EVENT_H

#include "TypesOfEvents.h"
#include "Event.h"
#include "StepInformation.h"
#include "FaseType.h"
#include "Exception.h"
#include <vector>
#include <string>
#include "Position.h"


class SendAttacksInfoEvent: public Event {
	public:
		// FALTA IMPLEMENTAR. 
		SendAttacksInfoEvent(StepInformation& step);
		~SendAttacksInfoEvent();
	private:
		SendAttacksInfoEvent(const SendAttacksInfoEvent &other) = delete;
		SendAttacksInfoEvent& operator=(const SendAttacksInfoEvent &other) = delete;
};

#endif
