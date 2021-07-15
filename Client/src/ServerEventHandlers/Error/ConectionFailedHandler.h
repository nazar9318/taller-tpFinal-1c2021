#ifndef CONECTION_FAILED_HANDLER_H
#define CONECTION_FAILED_HANDLER_H

#include <vector>
#include "Event.h"
#include "GameMap.h"
#include "Tile.h"
#include "FaseType.h"
#include "TypesOfEvents.h"
#include "Exception.h"

class ConectionFailedHandler {
	public:
		ConectionFailedHandler();

		void handle(Event& event, GameMap& map);

		~ConectionFailedHandler();

};


#endif
