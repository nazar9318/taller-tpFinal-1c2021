#ifndef CHANGE_ANGLE_EVENT_H
#define CHANGE_ANGLE_EVENT_H

#include "TypesOfEvents.h"
#include "Event.h"
#include <string>


class ChangeAngleEvent : public Event {
	public:
		// 0 <= angle < 360 
		ChangeAngleEvent(int angle);
		~ChangeAngleEvent();
	private:
		ChangeAngleEvent(const ChangeAngleEvent &other) = delete;
		ChangeAngleEvent& operator=(const ChangeAngleEvent &other) = delete;
};

#endif
