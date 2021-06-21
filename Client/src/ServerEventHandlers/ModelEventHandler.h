#ifndef _MODEL_EVENT_HANDLER_H
#define _MODEL_EVENT_HANDLER_H

#include <vector>
#include "TypesOfEvents.h"
#include "Event.h"
#include "Exception.h"

class ModelEventHandler{
		
	public:
		ModelEventHandler(); 

		void handle(Event& event); 

		~ModelEventHandler();

	private:
		ModelEventHandler(const ModelEventHandler &other) = delete;
		ModelEventHandler& operator=(const ModelEventHandler &other) = delete;
};

#endif
