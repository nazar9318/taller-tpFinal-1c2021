#ifndef RECEIVE_ATTACKS_HANDLER_H
#define RECEIVE_ATTACKS_HANDLER_H

#include <vector>
#include "Event.h"
#include "FaseType.h"
#include "GameMap.h"
#include "Team.h"
#include "FaseType.h"
#include "BombState.h"
#include "ClientBomb.h"
#include "SoundHandler.h"
#include "AttackEffect.h"

class ReceiveAttacksHandler {
	public:
		ReceiveAttacksHandler();

		void handle(FaseType& fase, Event& event, GameMap& map, AttackEffect& attack_effects);

		~ReceiveAttacksHandler();
};


#endif
