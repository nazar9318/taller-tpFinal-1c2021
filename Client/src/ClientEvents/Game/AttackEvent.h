#ifndef _ATTACK_EVENT_H
#define _ATTACK_EVENT_H

#include "TypesOfEvents.h"
#include "Event.h"
#include <string>


class AttackEvent: public Event {
	public:
		AttackEvent();
		~AttackEvent();
	private:
		AttackEvent(const AttackEvent &other) = delete;
		AttackEvent& operator=(const AttackEvent &other) = delete;
};

#endif
