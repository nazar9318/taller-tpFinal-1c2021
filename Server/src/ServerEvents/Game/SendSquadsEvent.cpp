#include "SendSquadsEvent.h"

SendSquadsEvent::SendSquadsEvent(std::vector<char> squads) {
	this->msg.push_back((char)ModelTypeEvent::SEND_SQUADS);
	std::copy(squads.begin(), squads.end(), std::back_inserter(msg));
}

SendSquadsEvent::~SendSquadsEvent() {}
