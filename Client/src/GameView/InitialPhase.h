#ifndef _INITIAL_PHASE_H
#define _INITIAL_PHASE_H

#include "Renderer.h"
#include "Texture.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "SDLException.h"
#include "Button.h"

#include "FaseType.h"

class InitialPhase {
	private:
		Renderer& renderer;
		Texture background;
		Texture button;
		Texture button_over;
		Texture button_pressed;

		Button ak47, awp, m3, primary_ammo, secondary_ammo;
		
		TTF_Font* font;
		int screen_width;
		int screen_height;

	public:
    InitialPhase(Renderer& renderer, int screen_width, int screen_height);

		void loadMedia();

		bool run();

		void render();

		~InitialPhase();

	private:
		void handleEvents(SDL_Event& event, SDL_Point& mousePosition);

		void handleAk47(SDL_Event& event);

		bool inside(SDL_Point& pos, SDL_Rect& box);


		InitialPhase(const InitialPhase &other) = delete;
		InitialPhase& operator=(const InitialPhase &other) = delete;
		InitialPhase(InitialPhase&& other) = delete;
		InitialPhase& operator=(InitialPhase&& other) = delete;
};

#endif
