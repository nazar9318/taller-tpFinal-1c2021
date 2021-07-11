#ifndef _INITIAL_FASE_H
#define _INITIAL_FASE_H

#include "Renderer.h"
#include "Texture.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "SDLException.h"
#include "Button.h"

class InitialFase {
	private:
		Renderer& renderer;
		Texture background;
		Button ak, awp, m3;
		TTF_Font* font;
		int screen_width;
		int screen_height;

	public:
    	InitialFase(Renderer& renderer, int screen_width, int screen_height);

		void loadMedia();

		void render();

		~InitialFase();

	private:
		InitialFase(const InitialFase &other) = delete;
		InitialFase& operator=(const InitialFase &other) = delete;
		InitialFase(InitialFase&& other) = delete;
		InitialFase& operator=(InitialFase&& other) = delete;
};

#endif
