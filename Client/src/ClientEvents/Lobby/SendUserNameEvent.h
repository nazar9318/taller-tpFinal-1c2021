#ifndef _SEND_USER_NAME_EVENT_H
#define _SEND_USER_NAME_EVENT_H

#include "TypesOfEvents.h"
#include "Event.h"
#include <string>


class SendUserNameEvent: public Event {
	public:
		SendUserNameEvent(std::string user_name);
		~SendUserNameEvent();
	private:
		SendUserNameEvent(const SendUserNameEvent &other) = delete;
		SendUserNameEvent& operator=(const SendUserNameEvent &other) = delete;
};

#endif
