#include "EntrySuccessfulEvent.h"

// Descripcion: Se envia este evento cuando el jugador logra 
//              crear o unirse satisfactoriamente a una partida. 
// POST: El mensaje: type|id en dos char.
EntrySuccessfulEvent::EntrySuccessfulEvent(char self_id) {
	this->msg.push_back(ModelTypeEvent::SUCCESSFUL_ENTRY);
	this->msg.push_back(self_id);
}

EntrySuccessfulEvent::~EntrySuccessfulEvent() {
}