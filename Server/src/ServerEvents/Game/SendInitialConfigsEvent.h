#ifndef _SEND_INITIAL_CONFIGS_EVENT_H
#define _SEND_INITIAL_CONFIGS_EVENT_H

#include "TypesOfEvents.h"
#include "Event.h"
#include <vector>
#include <string>
#include "Position.h"
#include "Configuration.h"


class SendInitialConfigsEvent: public Event {
	public:
		SendInitialConfigsEvent();
		~SendInitialConfigsEvent();
	private:
		SendInitialConfigsEvent(const SendInitialConfigsEvent &other) = delete;
		SendInitialConfigsEvent& operator=(const SendInitialConfigsEvent &other) = delete;
};

#endif
