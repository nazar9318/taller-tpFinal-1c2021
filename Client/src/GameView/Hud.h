#ifndef _HUD_H
#define _HUD_H

#include <string>
#include <map>

#include "Texture.h"
#include "Renderer.h"

#include "TypesOfEvents.h"

#define SYMBOL_WIDTH 64
#define SYMBOL_HEIGHT 64
#define AMMO_OFFSET window_width/2
#define AMMO_POSITION 11
#define NUMBERS_WIDTH 42
#define NUMBERS_HEIGHT 66
#define NUMBERS_OFFSET 6
#define INIFNITY_AMMO -1

class Hud {
	private:
		Renderer& renderer;

		Texture numbers;
		Texture hud_symbols;
		std::map<char, Texture> weapons;

		SDL_Rect clips[4];

		int window_width;
		int window_height;

		int life;
		int remaining_time;
		int money;
		int ammo;
		char weapon_type;
		bool has_bomb;

	public:

		Hud(Renderer& renderer, int window_width, int window_height);

		void loadMedia();

		void update_values(char life, int money, int ammo, char weapon_type, bool has_bomb);

		void render();

		~Hud();

	private:
		int numbers_offset(std::string& string, int& i);
		void renderLife();
		void renderMoney();
		void renderAmmo();
		void renderBomb();
		void renderWeapon();
		void setClips();
		Hud(const Hud &other) = delete;
		Hud& operator=(const Hud &other) = delete;
};


#endif
