#ifndef _SEND_FINAL_STEP_EVENT_H
#define _SEND_FINAL_STEP_EVENT_H

#include "TypesOfEvents.h"
#include "Event.h"
#include <vector>
#include <string>
#include "Position.h"
#include "StepInformation.h"


class SendFinalStepEvent: public Event {
	public:
		// Descripcion: Envia el tiempo que falta hasta
		//              que comienza la siguiente fase. 
		// POST: Se envia: type, wait(int)
		SendFinalStepEvent(StepInformation& step);
		~SendFinalStepEvent();
	private:
		SendFinalStepEvent(const SendFinalStepEvent &other) = delete;
		SendFinalStepEvent& operator=(const SendFinalStepEvent &other) = delete;
};

#endif
