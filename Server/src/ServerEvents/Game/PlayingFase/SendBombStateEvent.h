#ifndef _SEND_BOMB_STATE_EVENT_H
#define _SEND_BOMB_STATE_EVENT_H

#include "TypesOfEvents.h"
#include "Event.h"
#include <vector>
#include <string>
#include "Position.h"


class SendBombStateEvent: public Event {
	public:
		SendBombStateEvent(std::vector<char> bomb_info);
		~SendBombStateEvent();
	private:
		SendBombStateEvent(const SendBombStateEvent &other) = delete;
		SendBombStateEvent& operator=(const SendBombStateEvent &other) = delete;
};

#endif
