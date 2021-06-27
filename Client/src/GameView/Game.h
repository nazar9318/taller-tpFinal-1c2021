#ifndef _GAME_H
#define _GAME_H

#include <string>
#include <iostream>
#include "Event.h"
#include "ProtectedQueue.h"
#include "GameMap.h"
#include "ModelEventHandler.h"


#include "Window.h"
#include "Renderer.h"

#include <SDL2/SDL.h>

class Game {
	ProtectedQueue<Event>& model_events;
	ProtectedQueue<std::unique_ptr<Event>>& client_events;
	GameMap map;
	ModelEventHandler handler;
	bool is_running;

	Window window;
	Renderer renderer;

	public:
		Game(ProtectedQueue<Event>& model_events,
		ProtectedQueue<std::unique_ptr<Event>>& client_events);

		void execute();
		~Game();

	private:
		bool handle_events();
		void process_events();
		void update();
		void render();
		void handle_key_press(SDL_Event& event);
		void handle_key_release(SDL_Event& event);
		void handle_click(SDL_Event& event);
		void handle_unclick(SDL_Event& event);
		void handle_mouse_motion();



		Game(const Game &other) = delete;
		Game& operator=(const Game &other) = delete;
};


#endif
