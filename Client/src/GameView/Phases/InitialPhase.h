#ifndef _INITIAL_PHASE_H
#define _INITIAL_PHASE_H

#include "Renderer.h"
#include "Texture.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "SDLException.h"
#include "Button.h"
#include <map>
#include "TypesOfEvents.h"
#include "BuyWeaponEvent.h"
#include "BuyBulletsEvent.h"
#include <memory>
#include "Paths.h"
#include "ProtectedQueue.h"

#define NO_SECONDARY_AMMO -1


class InitialPhase {
	private:
		Renderer& renderer;
		ProtectedQueue<std::unique_ptr<Event>>& client_event;

		std::map<char, Button> buttons;

		Texture background;
		Texture buy_window;
		Texture button;
		Texture button_over;
		Texture button_pressed;
		Texture actual_money;
		Texture error_msg;

		bool successful_buy;
		int ticks_rendered;
		int number_of_weapons;
		char player_id;

		TTF_Font* font;
		int screen_width;
		int screen_height;

	public:
    InitialPhase(Renderer& renderer, int screen_width, int screen_height,
			 					ProtectedQueue<std::unique_ptr<Event>>& client, char player_id);

		void loadMedia();

		bool run();

		void addPrice(int price, PositionType weapon);

		void updateValues(char id, int money, BuyState buy_state, int number_of_weapons, int price_secconadary_ammo);

		void render();

		~InitialPhase();

	private:
		void handleEvents(SDL_Event& event, SDL_Point& mousePosition);

		void handleButton(SDL_Event& event, PositionType button);

		void handleError(BuyState buy_state);

		bool inside(SDL_Point& pos, SDL_Rect& box);

		void renderErrorMessage();

		void renderBuysWindow();

		void renderBackground();

		void updateMoney(int money);

		InitialPhase(const InitialPhase &other) = delete;
		InitialPhase& operator=(const InitialPhase &other) = delete;
		InitialPhase(InitialPhase&& other) = delete;
		InitialPhase& operator=(InitialPhase&& other) = delete;
};

#endif
