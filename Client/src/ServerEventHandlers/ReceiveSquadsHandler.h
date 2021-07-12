#ifndef RECIVE_SQUADS_HANDLER_H
#define RECIVE_SQUADS_HANDLER_H

#include <vector>
#include "Event.h"
#include "GameMap.h"
#include "Tile.h"
#include "FaseType.h"

class ReceiveSquadsHandler {
	public:
		ReceiveSquadsHandler();

		void handle(Event& event, GameMap& map);

		~ReceiveSquadsHandler();

};


#endif
