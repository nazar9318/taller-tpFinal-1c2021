#ifndef _SEND_FULL_MAP_EVENT_H
#define _SEND_FULL_MAP_EVENT_H

#include "TypesOfEvents.h"
#include "Event.h"
#include <vector>
#include <string>


class SendFullMapEvent: public Event {
	public:
		SendFullMapEvent(std::vector<char> map_info);
		~SendFullMapEvent();
	private:
		SendFullMapEvent(const SendFullMapEvent &other) = delete;
		SendFullMapEvent& operator=(const SendFullMapEvent &other) = delete;
};

#endif
