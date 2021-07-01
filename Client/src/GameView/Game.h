#ifndef _GAME_H
#define _GAME_H

#include <string>
#include <syslog.h>
#include <iostream>
#include "Event.h"
#include "ProtectedQueue.h"
#include "GameMap.h"
#include "ModelEventHandler.h"
#include "MoveEvent.h"
#include "GrabWeaponEvent.h"
#include "ChangeWeaponEvent.h"
#include "AttackEvent.h"
#include "StopAttackingEvent.h"
#include "Window.h"
#include "SDLException.h"
#include "Renderer.h"

#include "ClientPlayer.h"
#include "ClientCharacter.h"

#include <SDL2/SDL.h>

class Game {
	private:
		ProtectedQueue<Event>& model_events;
		ProtectedQueue<std::unique_ptr<Event>>& client_events;
		GameMap map;
		ModelEventHandler handler;
		bool is_running;
		ClientPlayer player;
		std::map<char, ClientCharacter> characters;
		Window window;
		Renderer renderer;

	public:
		Game(ProtectedQueue<Event>& model_events,
			ProtectedQueue<std::unique_ptr<Event>>& client_events,
			std::map<char, std::string>& characters, char& player_id);
		void execute();
		~Game();

	private:
		void loadMedia();
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
