#ifndef _GAME_H
#define _GAME_H

#include <string>
#include <iostream>
#include "ClientEvent.h"
#include "ModelEvent.h"
#include "ProtectedQueue.h"
#include "GameMap.h"
#include "FrameLimiter.h"

class Game {
	ProtectedQueue<ModelEvent>& model_events;
	ProtectedQueue<ClientEvent>& client_events;
	GameMap& map;
	bool is_running;

	public:
		Game(ProtectedQueue<ModelEvent>& model_events,
		 ProtectedQueue<ClientEvent>& client_events, GameMap& map);
		
		void execute();
		~Game();

	private:
		void handle_events();
		void process_events();
		void update();
		void render();


		Game(const Game &other) = delete;
		Game& operator=(const Game &other) = delete;
};


#endif
