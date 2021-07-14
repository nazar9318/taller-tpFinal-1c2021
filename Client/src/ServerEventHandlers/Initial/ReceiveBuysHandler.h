#ifndef RECEIVE_BUYS_HANDLER_H
#define RECEIVE_BUYS_HANDLER_H

#include <vector>
#include "Event.h"
#include "FaseType.h"
#include "GameMap.h"
#include "Team.h"
#include "FaseType.h"
#include "TypesOfEvents.h"


class ReceiveBuysHandler {
	public:
		ReceiveBuysHandler();

		void handle(FaseType& fase, Event& event, GameMap& map);

		~ReceiveBuysHandler();
};


#endif
