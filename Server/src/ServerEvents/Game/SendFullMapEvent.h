#ifndef _SEND_FULL_MAP_EVENT_H
#define _SEND_FULL_MAP_EVENT_H

#include "TypesOfEvents.h"
#include "Event.h"
#include <vector>
#include <string>
#include "Position.h"


class SendFullMapEvent: public Event {
	public:
		SendFullMapEvent(std::vector<Position*> map_info,
			 int x_lenght, int y_lenght);
		~SendFullMapEvent();
	private:
		SendFullMapEvent(const SendFullMapEvent &other) = delete;
		SendFullMapEvent& operator=(const SendFullMapEvent &other) = delete;
};

#endif
