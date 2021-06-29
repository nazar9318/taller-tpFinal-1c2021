#ifndef _GAME_MAP_H
#define _GAME_MAP_H

#include <string>
#include "Event.h"

#include "TileContainer.h"

class GameMap {
	private:
		Renderer& renderer;
		TileContainer tiles;

		int map_width;
		int map_height;

	public:
		GameMap(Renderer& renderer);
		void create();
		~GameMap();

	private:
		GameMap(const GameMap &other) = delete;
		GameMap& operator=(const GameMap &other) = delete;
};


#endif
