#ifndef _FINAL_PHASE_H
#define _FINAL_PHASE_H

#include "Renderer.h"
#include "Texture.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "SDLException.h"
#include <vector>
#include <string>
#include <sstream>

class FinalPhase {
	private:
		Renderer& renderer;
		Texture background;
		std::vector<std::string> names;
		std::vector<std::string> round_kills;
		std::vector<std::string> total_kills;
		TTF_Font* font;
		int screen_width;
		int screen_height;

	public:
    	FinalPhase(Renderer& renderer, int screen_width, int screen_height);
		void addScore(const std::string& name, int round_kills, int total_kills);
		void loadMedia();
		void render();
		~FinalPhase();

	private:
		FinalPhase(const FinalPhase &other) = delete;
		FinalPhase& operator=(const FinalPhase &other) = delete;
		FinalPhase(FinalPhase&& other) = delete;
		FinalPhase& operator=(FinalPhase&& other) = delete;
};

#endif
