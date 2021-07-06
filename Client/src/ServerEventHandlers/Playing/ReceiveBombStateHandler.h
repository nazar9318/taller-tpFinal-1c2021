#ifndef RECEIVE_BOMB_STATE_HANDLER_H
#define RECEIVE_BOMB_STATE_HANDLER_H

#include <vector>
#include "Event.h"
#include "FaseType.h"
#include "GameMap.h"
#include "Team.h"
#include "FaseType.h"
#include "BombState.h"


class ReceiveBombStateHandler {
	public:
		ReceiveBombStateHandler();

		void handle(FaseType& fase, Event& event, GameMap& map);

		~ReceiveBombStateHandler();
};


#endif
