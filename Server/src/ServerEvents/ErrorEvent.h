#ifndef _ERROR_EVENT_H
#define _ERROR_EVENT_H

#include "TypesOfEvents.h"
#include "Event.h"


class ErrorEvent: public Event {
	public:
		ErrorEvent(ServerError type_error);
		~ErrorEvent();
	private:
		ErrorEvent(const ErrorEvent &other) = delete;
		ErrorEvent& operator=(const ErrorEvent &other) = delete;
};

#endif
