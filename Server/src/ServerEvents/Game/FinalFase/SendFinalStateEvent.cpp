#include "SendFinalStateEvent.h"


SendFinalStateEvent::SendFinalStateEvent(StepInformation& step) {
	this->msg.push_back((char)ModelTypeEvent::FINAL_STATE);
	std::vector<char> final_state = step.get_reason_finish();
	std::copy(final_state.begin(), final_state.end(), std::back_inserter(msg));
}

SendFinalStateEvent::~SendFinalStateEvent() {
}
