#include "SendBuysEvent.h"


SendBuysEvent::SendBuysEvent(StepInformation& step) {
	this->msg.push_back((char)ModelTypeEvent::BUYS);

}

SendBuysEvent::~SendBuysEvent() {
}
