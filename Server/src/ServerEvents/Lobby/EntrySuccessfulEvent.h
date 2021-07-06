#ifndef _ENTRY_SUCCESSFUL_EVENT_H
#define _ENTRY_SUCCESSFUL_EVENT_H

#include "TypesOfEvents.h"
#include "Event.h"


class EntrySuccessfulEvent: public Event {
	public:
		// Descripcion: Se envia este evento cuando el jugador logra 
		//              crear o unirse satisfactoriamente a una partida. 
		// POST: El mensaje: type|id en dos char.
		EntrySuccessfulEvent(char self_id);
		~EntrySuccessfulEvent();
	private:
		EntrySuccessfulEvent(const EntrySuccessfulEvent &other) = delete;
		EntrySuccessfulEvent& operator=(const EntrySuccessfulEvent &other) = delete;
};

#endif
