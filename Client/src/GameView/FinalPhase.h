#ifndef _FINAL_PHASE_H
#define _FINAL_PHASE_H

#include "Renderer.h"
#include "Paths.h"
#include "Texture.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "SDLException.h"
#include <vector>
#include <string>
#include <sstream>
#define BACKGROUND_WIDTH 800
#define BACKGROUND_HEIGHT 600

class FinalPhase {
	private:
		Renderer& renderer;
		Texture background_victory;
		Texture background_defeat;
		std::vector<std::string> names;
		std::vector<bool> my_team;
		//std::vector<std::string> squad;
		std::vector<std::string> round_kills;
		std::vector<std::string> deaths;
		std::vector<std::string> money;
		std::vector<std::string> total_kills;
		TTF_Font* font;
		int screen_width;
		int screen_height;
		int wins_one;
		int wins_two;
		int my_squad;
		bool post_game;
		bool victory;
		int round;
		int total_rounds;
		void renderRequested(int x, const std::vector<std::string>& request);

	public:
    	FinalPhase(Renderer& renderer, int screen_width, int screen_height);
		void addScore(const std::string& name, bool my_team, int round_kills,
					int total_kills, int times_killed, int money, bool victory);
		void setSquadsPoints(int wins_one, int wins_two);
		void setRound(int current_round, int total_rounds);
		void setPlayerSquad(int squad);
		void renderBackground();
		void renderRounds();
		void renderSquadsPoints();
		void loadMedia();
		void render();
		void clean();
		void endGame();
		void renderPostGame();
		void renderRound();
		~FinalPhase();

	private:
		FinalPhase(const FinalPhase &other) = delete;
		FinalPhase& operator=(const FinalPhase &other) = delete;
		FinalPhase(FinalPhase&& other) = delete;
		FinalPhase& operator=(FinalPhase&& other) = delete;
};

#endif
