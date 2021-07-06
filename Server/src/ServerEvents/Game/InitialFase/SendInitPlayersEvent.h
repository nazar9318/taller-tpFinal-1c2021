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
		// Descripcion: Envia la informacion inicial
		//              de los jugadores antes de que comience la ronda. 
		// POST: El mensaje se construye como el type + la informacion
		//       que tenga el step al respecto.  
		SendInitPlayersEvent(StepInformation& step);
		~SendInitPlayersEvent();
	private:
		SendInitPlayersEvent(const SendInitPlayersEvent &other) = delete;
		SendInitPlayersEvent& operator=(const SendInitPlayersEvent &other) = delete;
};

#endif
