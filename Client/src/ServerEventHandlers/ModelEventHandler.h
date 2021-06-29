#ifndef _MODEL_EVENT_HANDLER_H
#define _MODEL_EVENT_HANDLER_H

#include <vector>
#include "TypesOfEvents.h"
#include "Event.h"
#include "Exception.h"

#include "GameMap.h"

#include "ReciveMapHandler.h"

class ModelEventHandler{
	private:
		ReciveMapHandler recive_map;
	public:
		ModelEventHandler();

		void handle(Event& event, GameMap& map);

		~ModelEventHandler();

	private:
		ModelEventHandler(const ModelEventHandler &other) = delete;
		ModelEventHandler& operator=(const ModelEventHandler &other) = delete;
};

#endif
