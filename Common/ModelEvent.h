#ifndef _MODEL_EVENT_H
#define _MODEL_EVENT_H

#include <string>
#include "TypesOfEvents.h"

class ModelEvent {
	TypeOfEvent type;
	std::string info;
	public:
		ModelEvent(TypeOfEvent t);
		ModelEvent() {}
		TypeOfEvent get_type();
		ModelEvent(ModelEvent&&) = default;
    	ModelEvent& operator = (ModelEvent&&) = default;
		~ModelEvent();

	private:
		ModelEvent(const ModelEvent &other) = delete;
		ModelEvent& operator=(const ModelEvent &other) = delete;
};


#endif
