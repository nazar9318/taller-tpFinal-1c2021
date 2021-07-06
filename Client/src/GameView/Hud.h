#ifndef _HUD_H
#define _HUD_H

#include <string>

#include "Texture.h"
#include "Renderer.h"

#define NUMBERS_WIDTH 42
#define NUMBERS_HEIGHT 66
#define NUMBERS_OFFSET 6

class Hud {
	private:
		Renderer& renderer;

		Texture money_icon;
		Texture numbers;

		int window_width;
		int window_height;

		int life;
		int remaining_time;
		int money;

	public:

		Hud(Renderer& renderer, int window_width, int window_height);

		void loadMedia();

		void update_values(char life, int money);

		void render();

		~Hud();

	private:
		int numbers_offset(std::string& string, int& i);
		Hud(const Hud &other) = delete;
		Hud& operator=(const Hud &other) = delete;
};


#endif
