#ifndef _MODEL_EVENT_H
#define _MODEL_EVENT_H

#include <string>

class ModelEvent {
	char type;
	public:
		ModelEvent();
		ModelEvent(ModelEvent&&) = default;
    	ModelEvent& operator = (ModelEvent&&) = default;
		~ModelEvent();

	private:
		ModelEvent(const ModelEvent &other) = delete;
		ModelEvent& operator=(const ModelEvent &other) = delete;
};


#endif
