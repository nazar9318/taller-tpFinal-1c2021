#ifndef _SEND_STEP_PLAYING_EVENT_H
#define _SEND_STEP_PLAYING_EVENT_H

#include "TypesOfEvents.h"
#include "Event.h"
#include "StepInformation.h"
#include "FaseType.h"
#include "Exception.h"
#include <vector>
#include <string>
#include "Position.h"


class SendStepPlayingEvent: public Event {
	public:
		// Descripcion: Envia la informacion de los
		//              characters en el ultimo step. 
		// POST: El mensaje se construye con la informacion
		//       del step. 
		SendStepPlayingEvent(StepInformation& step);
		~SendStepPlayingEvent();
	private:
		SendStepPlayingEvent(const SendStepPlayingEvent &other) = delete;
		SendStepPlayingEvent& operator=(const SendStepPlayingEvent &other) = delete;
};

#endif
