#ifndef _WEAPON_SPRITE_H
#define _WEAPON_SPRITE_H

#include <SDL2/SDL.h>
#include "SpriteContainer.h"

class WeaponSprite {
	private:
	   SDL_Rect box;
	   char type;
	   Texture& texture;

	public:
		WeaponSprite(int x, int y, char type);

		SDL_Rect& getBox();
		char getType();
		Texture& getTexture();

		~WeaponSprite();

		WeaponSprite(WeaponSprite&& other) = default;
		WeaponSprite& operator=(WeaponSprite&& other) = default;

	private:
		WeaponSprite(const WeaponSprite &other) = delete;
		WeaponSprite& operator=(const WeaponSprite &other) = delete;
};


#endif
