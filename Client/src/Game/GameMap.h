#ifndef _GAME_MAP_H
#define _GAME_MAP_H

#include <string>
#include "ModelEvent.h"


class GameMap {

	public:
		GameMap();
		void create(ModelEvent& starter_event);
		~GameMap();

	private:
		GameMap(const GameMap &other) = delete;
		GameMap& operator=(const GameMap &other) = delete;
};


#endif
