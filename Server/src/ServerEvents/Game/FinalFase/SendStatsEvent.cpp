#include "SendStatsEvent.h"


SendStatsEvent::SendStatsEvent(StepInformation& step) {
	this->msg.push_back((char)ModelTypeEvent::STATISTICS);

}

SendStatsEvent::~SendStatsEvent() {
}
