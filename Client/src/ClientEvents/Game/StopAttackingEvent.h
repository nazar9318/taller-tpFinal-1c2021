#ifndef _STOP_ATTACK_EVENT_H
#define _STOP_ATTACK_EVENT_H

#include "TypesOfEvents.h"
#include "Event.h"
#include <string>

class StopAttack: public Event {
	public:
		StopAttack();
		~StopAttack();
	private:
		StopAttack(const StopAttack &other) = delete;
		StopAttack& operator=(const StopAttack &other) = delete;
};

#endif
