#ifndef _GAME_MAP_H
#define _GAME_MAP_H

#include <string>
#include "Event.h"


class GameMap {

	public:
		GameMap();
		void create(Event& starter_event);
		~GameMap();

	private:
		GameMap(const GameMap &other) = delete;
		GameMap& operator=(const GameMap &other) = delete;
};


#endif
