#ifndef _TILE_H
#define _TILE_H

#include <SDL2/SDL.h>
#include "TileContainer.h"

#define TILE_WIDTH 64
#define TILE_HEIGHT 64

class Tile {
	private:
		SDL_Rect box;
		char type;
		Texture& texture;

	public:
		Tile(int x, int y, char type);

		SDL_Rect& getBox();
		char getType();
		Texture& getTexture();

		~Tile();

		Tile(Tile&& other) = default;
		Tile& operator=(Tile&& other) = default;

	private:
		Tile(const Tile &other) = delete;
		Tile& operator=(const Tile &other) = delete;
};


#endif
