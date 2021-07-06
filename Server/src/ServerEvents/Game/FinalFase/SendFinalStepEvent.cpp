#include "SendFinalStepEvent.h"

// Descripcion: Envia el tiempo que falta hasta
//              que comienza la siguiente fase. 
// POST: Se envia: type, wait(int)
SendFinalStepEvent::SendFinalStepEvent(StepInformation& step) {
	this->msg.push_back((char)ModelTypeEvent::FINAL_STEP);
	int wait = step.get_wait();
	push_back(wait);
}

SendFinalStepEvent::~SendFinalStepEvent() {
}
