#ifndef _GAME_H
#define _GAME_H

#include <string>
#include <syslog.h>
#include <iostream>
#include <chrono>
#include <thread>
#include "Event.h"
#include "ProtectedQueue.h"
#include "GameMap.h"
#include "ModelEventHandler.h"
#include "ChangeWeaponEvent.h"
#include "StartPlantBombEvent.h"
#include "StartDeactivateBombEvent.h"
#include "StopPlantBombEvent.h"
#include "StopDeactivateBombEvent.h"
#include "MoveEvent.h"
#include "GrabWeaponEvent.h"
#include "AttackEvent.h"
#include "StopAttackingEvent.h"
#include "Window.h"
#include "SDLException.h"
#include "Renderer.h"
#include "ClientPlayer.h"
#include "ClientCharacter.h"
#include "ChangeAngleEvent.h"
#include "TypesOfEvents.h"
#include <SDL2/SDL.h>
#include "FaseType.h"
#include "Camera.h"
#include "Hud.h"
#include "InitialFase.h"
#include "FinalPhase.h"

class Game {
	private:
		ProtectedQueue<Event>& model_events;
		ProtectedQueue<std::unique_ptr<Event>>& client_events;
		GameMap map;
		Hud hud;
		InitialFase initial_fase;
		FinalPhase final_phase;
		ModelEventHandler handler;
		bool is_running;
		ClientPlayer player;
		std::map<char, ClientCharacter> characters;
		Window window;
		Renderer renderer;
		Camera camera;
		int prev_mouse_x;
		int prev_mouse_y;
		FaseType fase;
		bool final_phase_rendered;

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
