#ifndef RECEIVE_INIT_CONFIGS_HANDLER_H
#define RECEIVE_INIT_CONFIGS_HANDLER_H

#include <vector>
#include "Event.h"
#include "GameMap.h"
#include "Tile.h"
#include "FaseType.h"

class ReceiveInitConfigsHandler {
	public:
		ReceiveInitConfigsHandler();

		void handle(Event& event, GameMap& map);

		~ReceiveInitConfigsHandler();

};


#endif
