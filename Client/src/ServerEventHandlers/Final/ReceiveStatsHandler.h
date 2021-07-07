#ifndef RECEIVE_STATS_HANDLER_H
#define RECEIVE_STATS_HANDLER_H

#include <vector>
#include "Event.h"
#include "FaseType.h"
#include "GameMap.h"
#include "Team.h"
#include "FaseType.h"

class ReceiveStatsHandler {
	public:
		ReceiveStatsHandler();

		void handle(FaseType& fase, Event& event, GameMap& map);

		~ReceiveStatsHandler();
};

#endif
