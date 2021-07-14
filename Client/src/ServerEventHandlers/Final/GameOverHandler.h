#ifndef GAME_OVER_HANDLER_H
#define GAME_OVER_HANDLER_H

#include <vector>
#include "Event.h"
#include "GameMap.h"
#include "Team.h"
#include "FaseType.h"
#include "ReasonFinish.h"
#include "BombState.h"
#include "ClientBomb.h"


class GameOverHandler {
	public:
		GameOverHandler();

		void handle(FaseType& fase, Event& event, GameMap& map);

		~GameOverHandler();
};

#endif
