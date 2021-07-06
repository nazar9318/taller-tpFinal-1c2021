#ifndef RECEIVE_INIT_PLAYERS_HANDLER_H
#define RECEIVE_INIT_PLAYERS_HANDLER_H

#include <vector>
#include "Event.h"
#include "FaseType.h"
#include "GameMap.h"
#include "Team.h"
#include "FaseType.h"


class ReceiveInitPlayersHandler {
	public:
		ReceiveInitPlayersHandler();

		void handle(FaseType& fase, Event& event, GameMap& map);

		~ReceiveInitPlayersHandler();
};


#endif
