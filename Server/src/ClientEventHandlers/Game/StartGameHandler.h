#ifndef START_GAME_HANDLER_H
#define START_GAME_HANDLER_H

#include <map>
#include "TypesOfEvents.h"
#include "SendFullMapEvent.h"
#include "Player.h"
#include "GameWorld.h"

class StartGameHandler{
	public:
		StartGameHandler();
		void handle(Event& event, std::map<char, Player*>& players, GameWorld& game_world);
		~StartGameHandler();
};

#endif