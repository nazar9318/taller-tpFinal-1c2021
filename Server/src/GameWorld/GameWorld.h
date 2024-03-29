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
#include "include/box2d/box2d.h"
#include "include/box2d/b2_math.h"
#include "Team.h"
#include "Position.h"
#include "StepInformation.h"
#include "AttackInformation.h"
#include "FaseType.h"
#include "Character.h"
#include "Bomb.h"
#include "SquadsManager.h"

class GameWorld {
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
		Bomb bomb;
		SquadsManager squad_manager;
		int players_online;

	public:
		GameWorld(const std::string& map_type);
		void add_player_if_not_full(char id);
		void delete_player(char id);
		void start();

		// false if the game is finished.
		bool simulate_step();
		StepInformation& get_step_info();

		std::vector<Position*> get_ground_info();
		std::list<std::unique_ptr<Weapon>>&  get_weapons_info();
		void get_limits(int& x_size, int&y_size);

		Character& get_character(char id);

		void add_weapon(const b2Vec2& pos, Weapon* weapon);
		bool get_closest_weapon(b2Vec2 char_pos, Weapon** weapon);
		bool activate_bomb(char id, b2Vec2& pos);
		bool deactivate_bomb(Team team, char id, b2Vec2& pos);
		void stop_activating_bomb(char id);
		void stop_deactivating_bomb(char id);
		bool grab_bomb(char id, Team team, b2Vec2& pos);
		FaseType get_fase();
		std::vector<char> bomb_info();
		std::vector<char> get_squads();
		void get_wins(int& squad_one, int& squad_two);
		char get_last_winner();
		~GameWorld();


	private:
		bool round_finished();
		void change_teams();
		void simulate_playing_step();
		void prepare_new_round();
		void charge_stats();
		void handle_attack(std::map<char, Character>::iterator& it,
								 AttackInformation& attack);
		void assign_bomb();
		void give_bonifications();

		GameWorld(const GameWorld &other) = delete;
		GameWorld& operator=(const GameWorld &other) = delete;
};


#endif
