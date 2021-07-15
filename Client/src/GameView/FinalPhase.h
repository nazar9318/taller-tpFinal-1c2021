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
		std::vector<std::string> team;
		std::vector<std::string> squad;
		std::vector<std::string> round_kills;
		std::vector<std::string> total_kills;
		TTF_Font* font;
		int screen_width;
		int screen_height;
		bool post_game;
		void teamWinner(std::string& winner, int& count);
		void playerWinner(std::string& winner, int& count);
		void renderRequested(int x, const std::vector<std::string>& request);
		void renderSquadScores();
		void renderTeamScores();

	public:
    	FinalPhase(Renderer& renderer, int screen_width, int screen_height);
		void addScore(const std::string& name, const std::string& team,
				int squad, int round_kills, int total_kills);
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
