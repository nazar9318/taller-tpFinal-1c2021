#include "SendFinalStateEvent.h"


SendFinalStateEvent::SendFinalStateEvent(StepInformation& step) {
	this->msg.push_back((char)ModelTypeEvent::FINAL_STATE);

}

SendFinalStateEvent::~SendFinalStateEvent() {
}
