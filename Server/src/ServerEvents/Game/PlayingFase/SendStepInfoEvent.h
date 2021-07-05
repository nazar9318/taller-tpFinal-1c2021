#ifndef _SEND_STEP_INFO_EVENT_H
#define _SEND_STEP_INFO_EVENT_H

#include "TypesOfEvents.h"
#include "Event.h"
#include "StepInformation.h"
#include "FaseType.h"
#include "Exception.h"
#include <vector>
#include <string>
#include "Position.h"


class SendStepInfoEvent: public Event {
	public:
		SendStepInfoEvent(StepInformation& step);
		~SendStepInfoEvent();
	private:
		SendStepInfoEvent(const SendStepInfoEvent &other) = delete;
		SendStepInfoEvent& operator=(const SendStepInfoEvent &other) = delete;
};

#endif
