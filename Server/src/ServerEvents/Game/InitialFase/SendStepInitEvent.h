#ifndef _SEND_STEP_INIT_EVENT_H
#define _SEND_STEP_INIT_EVENT_H

#include "TypesOfEvents.h"
#include "Event.h"
#include <vector>
#include <string>
#include "Position.h"
#include "StepInformation.h"



class SendStepInitEvent: public Event {
	public:
		// Descripcion: Envia el tiempo que falta hasta
		//              que comienza la siguiente fase. 
		// POST: Se envia: type, wait(int)
		SendStepInitEvent(StepInformation& step);
		~SendStepInitEvent();
	private:
		SendStepInitEvent(const SendStepInitEvent &other) = delete;
		SendStepInitEvent& operator=(const SendStepInitEvent &other) = delete;
};

#endif
