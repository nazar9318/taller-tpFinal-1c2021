#ifndef _GAME_MAP_H
#define _GAME_MAP_H

#include <string>
#include "Event.h"

#include "TileContainer.h"
#include "Tile.h"

class GameMap {
	private:
		Renderer& renderer;

		TileContainer& tile_container;
		std::vector<Tile> tiles;

		int map_width;
		int map_height;

		// Area a renderizar
		int x_min = 0, x_max = 0, y_min = 0, y_max = 0;

	public:
		GameMap(Renderer& renderer);
		void create();
		void setSize(int& width, int& height);

		void addTile(Tile tile);
		void loadMedia();

		/*------------Metodos para render--------------*/
		void setRenderArea();

		void renderGround();
		~GameMap();

	private:
		GameMap(const GameMap &other) = delete;
		GameMap& operator=(const GameMap &other) = delete;
};


#endif
