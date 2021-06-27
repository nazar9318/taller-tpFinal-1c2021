#ifndef _TILE_H
#define _TILE_H

class Tile {

	public:
		Tile();
		~Tile();

	private:
		Tile(const Tile &other) = delete;
		Tile& operator=(const Tile &other) = delete;
};


#endif
