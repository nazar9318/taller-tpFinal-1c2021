#ifndef RECEIVE_FINAL_STATE_HANDLER_H
#define RECEIVE_FINAL_STATE_HANDLER_H

#include <vector>
#include "Event.h"
#include "GameMap.h"
#include "Team.h"
#include "FaseType.h"
#include "ReasonFinish.h"
#include "BombState.h"


class ReceiveFinalStateHandler {
	public:
		ReceiveFinalStateHandler();

		void handle(FaseType& fase, Event& event, GameMap& map);

		~ReceiveFinalStateHandler();
};

#endif
