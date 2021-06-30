#include "StopAttackingEvent.h"


StopAttack::StopAttack() {
	this->msg.push_back((char)ClientTypeEvent::STOP_ATTACKING);
}


StopAttack::~StopAttack() {}
