#include "SendStepInitEvent.h"


SendStepInitEvent::SendStepInitEvent(StepInformation& step) {
	this->msg.push_back((char)ModelTypeEvent::INIT_STEP);
	int wait = step.get_wait();
	push_back(wait);
}

SendStepInitEvent::~SendStepInitEvent() {
}
