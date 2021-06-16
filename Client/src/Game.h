#ifndef _GAME_H
#define _GAME_H

#include <string>
#include <iostream>
#include "ClientEvent.h"
#include "ModelEvent.h"
#include "ProtectedQueue.h"
#include "GameMap.h"

class Game {
	ProtectedQueue<ModelEvent>& model_events;
	ProtectedQueue<ClientEvent>& client_events;
	GameMap& map;

	public:
		Game(ProtectedQueue<ModelEvent>& model_events,
		 ProtectedQueue<ClientEvent>& client_events, GameMap& map);
		
		void execute();
		~Game();

	private:
		Game(const Game &other) = delete;
		Game& operator=(const Game &other) = delete;
};


#endif
