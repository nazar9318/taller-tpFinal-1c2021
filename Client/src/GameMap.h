#ifndef _GAME_MAP_H
#define _GAME_MAP_H

#include <string>

class GameMap {

	public:
		GameMap();

		~GameMap();

	private:
		GameMap(const GameMap &other) = delete;
		GameMap& operator=(const GameMap &other) = delete;
};


#endif
