#ifndef _GAME_WORLD_H
#define _GAME_WORLD_H

#include <mutex>
#include "ExceptionMatchFull.h"
#include <vector>

class GameWorld {
		std::mutex m; 
		int number_players_allowed;
		int number_players;

	public:
		GameWorld(const std::string& map_type);
		void add_player_if_not_full(int id);
		void delete_player(int id);
		void start();
		void simulate_step();
		std::vector<char> get_players_info();
		std::vector<char> get_all_info();
		~GameWorld();
	
	private:
		GameWorld(const GameWorld &other) = delete;
		GameWorld& operator=(const GameWorld &other) = delete;
};


#endif
