#ifndef _RECEIVE_MAPS_EVENT_H
#define _RECEIVE_MAPS_EVENT_H

#include "TypesOfEvents.h"
#include "Event.h"
#include <string>


class ReceiveMapsEvent: public Event {
	public:
		ReceiveMapsEvent();
		~ReceiveMapsEvent();
	private:
		ReceiveMapsEvent(const ReceiveMapsEvent &other) = delete;
		ReceiveMapsEvent& operator=(const ReceiveMapsEvent &other) = delete;
};

#endif
