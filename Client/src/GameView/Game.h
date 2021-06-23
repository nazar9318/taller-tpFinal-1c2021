#ifndef _GAME_H
#define _GAME_H

#include <string>
#include <iostream>
#include "Event.h"
#include "ProtectedQueue.h"
#include "GameMap.h"
#include "ModelEventHandler.h"

class Game {
	ProtectedQueue<Event>& model_events;
	ProtectedQueue<Event>& client_events;
	GameMap& map;
	ModelEventHandler handler;
	bool is_running;

	public:
		Game(ProtectedQueue<Event>& model_events,
		ProtectedQueue<Event>& client_events, GameMap& map);

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
