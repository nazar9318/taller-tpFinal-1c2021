#ifndef _GAME_WORLD_H
#define _GAME_WORLD_H

#include <mutex>
#include "GroundMap.h"
#include "ExceptionMatchFull.h"
#include <vector>
#include <map>
#include "../../libs/box2d/include/box2d/box2d.h"
#include "../../libs/box2d/include/box2d/b2_math.h"
#include "team.h"
#include "character.h"
#include "Position.h"
#include "StepInformation.h"


class GameWorld {
		std::mutex m; 
		int number_players_allowed;
		int number_players;
		GroundMap ground;
		Team actual_team;
		b2World* world;
		StepInformation step_info;
		// (id, character)
		std::map<int, Character> characters; 
	public:
		GameWorld(const std::string& map_type);
		void add_player_if_not_full(int id);
		void delete_player(int id);
		void start();
		
		// false if the game is finished. 
		bool simulate_step();
		const StepInformation& get_step_info();
		std::vector<char> get_players_info();

		std::vector<Position*> get_ground_info();
		void get_limits(int& x_size, int&y_size);
		~GameWorld();
	
	private:
		GameWorld(const GameWorld &other) = delete;
		GameWorld& operator=(const GameWorld &other) = delete;
};


#endif
