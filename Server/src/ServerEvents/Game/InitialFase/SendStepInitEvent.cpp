#include "SendStepInitEvent.h"

// Descripcion: Envia el tiempo que falta hasta
//              que comienza la siguiente fase. 
// POST: Se envia: type, wait(int)
SendStepInitEvent::SendStepInitEvent(StepInformation& step) {
	this->msg.push_back((char)ModelTypeEvent::INIT_STEP);
	int wait = step.get_wait();
	push_back(wait);
}

SendStepInitEvent::~SendStepInitEvent() {
}
