#include "SendFinalStepEvent.h"


SendFinalStepEvent::SendFinalStepEvent(StepInformation& step) {
	this->msg.push_back((char)ModelTypeEvent::FINAL_STEP);
	int wait = step.get_wait();
	push_back(wait);
}

SendFinalStepEvent::~SendFinalStepEvent() {
}
