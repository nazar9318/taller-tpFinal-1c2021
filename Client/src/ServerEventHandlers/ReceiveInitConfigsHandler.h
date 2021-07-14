#ifndef RECEIVE_INIT_CONFIGS_HANDLER_H
#define RECEIVE_INIT_CONFIGS_HANDLER_H

#include <vector>
#include "Event.h"
#include "GameMap.h"
#include "Tile.h"
#include "FaseType.h"
#include "TypesOfEvents.h"
#include "InitialPhase.h"

class ReceiveInitConfigsHandler {
	public:
		ReceiveInitConfigsHandler();

		void handle(Event& event, GameMap& map, InitialPhase& initial_phase);

		~ReceiveInitConfigsHandler();

};


#endif
