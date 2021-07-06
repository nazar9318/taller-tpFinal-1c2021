#ifndef RECEIVE_INIT_STEP_HANDLER_H
#define RECEIVE_INIT_STEP_HANDLER_H

#include <vector>
#include "Event.h"
#include "FaseType.h"
#include "GameMap.h"
#include "Team.h"
#include "FaseType.h"


class ReceiveInitStepHandler {
	public:
		ReceiveInitStepHandler();

		void handle(FaseType& fase, Event& event, GameMap& map);

		~ReceiveInitStepHandler();
};


#endif
