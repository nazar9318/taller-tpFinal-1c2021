#ifndef _GAME_WORLD_H
#define _GAME_WORLD_H

#include <mutex>
#include "GameWorldTypes.h"
#include "ExceptionMatchFull.h"


class GameWorld {
		std::mutex m; 
		int number_players_allowed;
		int number_players;

	public:
		GameWorld();
		virtual void add_player_if_not_full(int id);
		virtual void delete_player(int id);
		~GameWorld();
	
	private:
		GameWorld(const GameWorld &other) = delete;
		GameWorld& operator=(const GameWorld &other) = delete;
};


#endif
