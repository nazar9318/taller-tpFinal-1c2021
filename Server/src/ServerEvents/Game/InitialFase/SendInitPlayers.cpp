#include "SendInitPlayersEvent.h"


SendInitPlayersEvent::SendInitPlayersEvent(StepInformation& step) {
	this->msg.push_back((char)ModelTypeEvent::INITIAL_PLAYERS);
	std::vector<char> v = step.get_players_init();
	std::copy(v.begin(), v.end(), std::back_inserter(msg));
}

SendInitPlayersEvent::~SendInitPlayersEvent() {
}
