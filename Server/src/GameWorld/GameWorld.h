#ifndef _GAME_WORLD_H
#define _GAME_WORLD_H

#include <mutex>
#include <vector>
#include <list>
#include <unordered_map>
#include <memory>

#include "Weapon.h"
#include "GroundMap.h"
#include "ErrorEvent.h"
#include "Configuration.h"
#include "ExceptionInvalidCommand.h"
#include "../../libs/box2d/include/box2d/box2d.h"
#include "../../libs/box2d/include/box2d/b2_math.h"
#include "Team.h"
#include "Position.h"
#include "StepInformation.h"
#include "FaseType.h"
#include "Character.h"

class GameWorld {
		std::mutex m;
		int number_players;
		GroundMap ground;
		Team actual_team;
		b2World* world;
		StepInformation step_info;
		unsigned int number_tics;
		int number_round;
		std::map<char, Character> characters; 
		std::list<Block> blocks;
		FaseType fase_type;
		std::list<std::unique_ptr<Weapon>> weapons_in_ground;
	public:
		GameWorld(const std::string& map_type);
		void add_player_if_not_full(char id);
		void delete_player(char id);
		void start();
		
		// false if the game is finished. 
		bool simulate_step();
		StepInformation& get_step_info();

		std::vector<Position*> get_ground_info();
		void get_limits(int& x_size, int&y_size);
		
		Character& get_character(char id);
		~GameWorld();

	
	private:
		bool round_finished();
		void change_teams();
		void simulate_playing_step();
		void prepare_new_round();
		void charge_stats();
		GameWorld(const GameWorld &other) = delete;
		GameWorld& operator=(const GameWorld &other) = delete;
};


#endif
