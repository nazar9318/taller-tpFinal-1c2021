#include "SendBuysEvent.h"


SendBuysEvent::SendBuysEvent(StepInformation& step) {
	this->msg.push_back((char)ModelTypeEvent::BUYS);
	std::vector<char> v = step.get_buys();
	std::copy(v.begin(), v.end(), std::back_inserter(msg));
}

SendBuysEvent::~SendBuysEvent() {
}
