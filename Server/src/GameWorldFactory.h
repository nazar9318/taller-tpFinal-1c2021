#ifndef GAME_WORLD_FACTORY_H
#define GAME_WORLD_FACTORY_H

#include "GameWorldTypes.h"
#include "GameWorld.h"
#include "Exception.h"

class GameWorldFactory {
	public:
		GameWorldFactory() = delete;
		~GameWorldFactory() = delete;
		static GameWorld* create(GameWorldType type);
};

#endif
