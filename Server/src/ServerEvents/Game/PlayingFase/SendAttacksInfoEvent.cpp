#include "SendAttacksInfoEvent.h"


SendAttacksInfoEvent::SendAttacksInfoEvent(StepInformation& step) {
	this->msg.push_back((char)ModelTypeEvent::ATTACKS_INFO);
// std::vector<char> attacks_info = step.get_attacks();
// std::copy(attacks_info.begin(),
// attacks_info.end(), std::back_inserter(this->msg));

}

SendAttacksInfoEvent::~SendAttacksInfoEvent() {
	
}