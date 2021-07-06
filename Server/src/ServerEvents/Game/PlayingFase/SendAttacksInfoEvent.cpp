#include "SendAttacksInfoEvent.h"


SendAttacksInfoEvent::SendAttacksInfoEvent(StepInformation& step) {
	this->msg.push_back((char)ModelTypeEvent::ATTACKS_INFO);

}

SendAttacksInfoEvent::~SendAttacksInfoEvent() {
	
}