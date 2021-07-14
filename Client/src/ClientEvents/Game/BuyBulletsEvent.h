#ifndef _BUY_BULLETS_EVENT_H
#define _BUY_BULLETS_EVENT_H

#include "TypesOfEvents.h"
#include "Event.h"
#include <string>


class BuyBulletsEvent: public Event {
	public:
		BuyBulletsEvent(char weapon);
		~BuyBulletsEvent();
	private:
		BuyBulletsEvent(const BuyBulletsEvent &other) = delete;
		BuyBulletsEvent& operator=(const BuyBulletsEvent &other) = delete;
};

#endif
