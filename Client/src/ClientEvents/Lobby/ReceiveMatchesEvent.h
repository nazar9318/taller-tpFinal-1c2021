#ifndef _RECEIVE_MATCHES_EVENT_H
#define _RECEIVE_MATCHES_EVENT_H

#include "TypesOfEvents.h"
#include "Event.h"
#include <string>


class ReceiveMatchesEvent: public Event {
	public:
		ReceiveMatchesEvent();
		~ReceiveMatchesEvent();
	private:
		ReceiveMatchesEvent(const ReceiveMatchesEvent &other) = delete;
		ReceiveMatchesEvent& operator=(const ReceiveMatchesEvent &other) = delete;
};

#endif
