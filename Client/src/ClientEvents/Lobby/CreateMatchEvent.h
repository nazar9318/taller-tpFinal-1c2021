#ifndef _CREATE_MATCH_EVENT_H
#define _CREATE_MATCH_EVENT_H

#include "TypesOfEvents.h"
#include "Event.h"
#include <string>


class CreateMatchEvent: public Event {
	public:
		CreateMatchEvent(std::string match_name, std::string map_name);
		~CreateMatchEvent();
	private:
		CreateMatchEvent(const CreateMatchEvent &other) = delete;
		CreateMatchEvent& operator=(const CreateMatchEvent &other) = delete;
};

#endif
