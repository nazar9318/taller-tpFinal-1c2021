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
#include "InitialPhase.h"
#include "FinalPhase.h"
#include "AttackEffect.h"
#include "ClientConfiguration.h"
#include "Cursor.h"
#include "Paths.h"

class Game {
	private:
		ProtectedQueue<Event>& model_events;
		ProtectedQueue<std::unique_ptr<Event>>& client_events;
		Window window;
		Renderer renderer;
		Camera camera;
		Cursor cursor;
		GameMap map;
		Hud hud;
		ClientBomb bomb;
		InitialPhase initial_phase;
		FinalPhase final_phase;
		ModelEventHandler handler;
		bool is_running;
		bool not_finished;
		ClientPlayer player;
		std::map<char, ClientCharacter> characters;
		FaseType fase;
		AttackEffect attack_effects;

	public:
		Game(ProtectedQueue<Event>& model_events,
			ProtectedQueue<std::unique_ptr<Event>>& client_events,
			std::map<char, std::string>& characters, char& player_id);
		void execute();
		~Game();

	private:
		void loadMedia();
		bool handle_events();
		bool handle_finished_game();
		void process_events();
		void update();
		void render();
		void handle_key_press(SDL_Event& event);
		void handle_key_release(SDL_Event& event);
		void handle_click(SDL_Event& event);
		void handle_unclick(SDL_Event& event);
		void handle_window_event(SDL_Event& event);
		void handle_mouse_motion();
		Game(const Game &other) = delete;
		Game& operator=(const Game &other) = delete;
};

#endif
