#ifndef RECIVE_MAP_HANDLER_H
#define RECIVE_MAP_HANDLER_H

#include <vector>
#include "Event.h"
#include "GameMap.h"
#include "Tile.h"
#include "FaseType.h"

class ReciveMapHandler {
	public:
		ReciveMapHandler();

		void handle(Event& event, GameMap& map);

		~ReciveMapHandler();

};


#endif
