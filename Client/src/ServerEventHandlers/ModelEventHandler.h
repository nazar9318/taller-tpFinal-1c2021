#ifndef _MODEL_EVENT_HANDLER_H
#define _MODEL_EVENT_HANDLER_H

#include <vector>
#include "TypesOfEvents.h"
#include "Event.h"
#include "Exception.h"

#include "GameMap.h"
#include "FaseType.h"
#include "ReciveMapHandler.h"
#include "ReciveWeaponHandler.h"
#include "ReciveStepHandler.h"

class ModelEventHandler{
	private:
		ReciveMapHandler recive_map;
		ReciveWeaponHandler recive_weapons;
		ReciveStepHandler recive_step;
	public:
		ModelEventHandler();

		// POST: Retorna la fase actual
		void handle(FaseType& fase, Event& event, GameMap& map);

		~ModelEventHandler();

	private:
		ModelEventHandler(const ModelEventHandler &other) = delete;
		ModelEventHandler& operator=(const ModelEventHandler &other) = delete;
};

#endif
