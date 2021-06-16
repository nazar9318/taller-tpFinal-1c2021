#ifndef _MODEL_EVENT_H
#define _MODEL_EVENT_H

#include <string>

class ModelEvent {
	
	public:
		ModelEvent();

		~ModelEvent();

	private:
		ModelEvent(const ModelEvent &other) = delete;
		ModelEvent& operator=(const ModelEvent &other) = delete;
};


#endif
