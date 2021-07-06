#include "SendStatsEvent.h"


SendStatsEvent::SendStatsEvent(StepInformation& step) {
	this->msg.push_back((char)ModelTypeEvent::STATISTICS);
	std::vector<char> stats = step.get_stats();
	std::copy(stats.begin(), stats.end(), std::back_inserter(msg));
}

SendStatsEvent::~SendStatsEvent() {
}
