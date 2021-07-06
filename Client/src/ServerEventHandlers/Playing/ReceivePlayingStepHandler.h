#ifndef RECEIVE_PLAYING_STEP_HANDLER_H
#define RECEIVE_PLAYING_STEP_HANDLER_H

#include <vector>
#include "Event.h"
#include "FaseType.h"
#include "GameMap.h"
#include "Team.h"
#include "FaseType.h"


class ReceivePlayingStepHandler {
	public:
		ReceivePlayingStepHandler();

		void handle(FaseType& fase, Event& event, GameMap& map);

		~ReceivePlayingStepHandler();
};


#endif
