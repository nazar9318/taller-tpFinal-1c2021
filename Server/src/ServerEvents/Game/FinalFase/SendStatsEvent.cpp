#include "SendStatsEvent.h"


SendStatsEvent::SendStatsEvent(StepInformation& step, bool finished) {
	this->msg.push_back((char)ModelTypeEvent::STATISTICS);
	this->msg.push_back((char)finished);
	std::vector<char> stats = step.get_stats();
	std::copy(stats.begin(), stats.end(), std::back_inserter(msg));
}

SendStatsEvent::~SendStatsEvent() {
}
