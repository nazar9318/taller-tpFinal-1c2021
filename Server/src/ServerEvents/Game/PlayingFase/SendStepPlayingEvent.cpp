#include "SendStepPlayingEvent.h"
#include <syslog.h>

SendStepPlayingEvent::SendStepPlayingEvent(StepInformation& step) {
	this->msg.push_back((char)ModelTypeEvent::PLAYING_STEP);
	std::vector<char> players_info = step.get_players_info();
	std::copy(players_info.begin(),
				players_info.end(), std::back_inserter(this->msg));
}

SendStepPlayingEvent::~SendStepPlayingEvent() {}
