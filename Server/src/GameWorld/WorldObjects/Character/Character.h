#ifndef CHARACTER_H
#define CHARACTER_H

class AttackInformation;
class Weapon;
class WeaponBomb;
class WeaponWhite;
class WeaponPistol;
class WeaponShotgun;
class WeaponAutomatic;

#include "Position.h"
#include "Weapon.h"
#include "AttackInformation.h"
#include "Team.h"
#include "Configuration.h"
#include "Block.h"
#include "Exception.h"
#include "TypesOfEvents.h"
#include "ExceptionInvalidCommand.h"
#include "../../libs/box2d/include/box2d/box2d.h"
#include "../../libs/box2d/include/box2d/b2_math.h"
#include <vector>
#include <list>
#include <iostream>
#include <memory>

class Character {
	private:
		char life_points;
		int money;
		Team team;
		std::vector<std::unique_ptr<Weapon>> weapons;
		int current_weapon;
		int number_weapons;
		b2Body* character_body;
		Direction move_state;
		int angle;
		bool blocked;
		int round_kills;
		int total_kills;
		b2Vec2 last_pos;
		int times_killed;

	public:
		Character(Team team, b2World* world,
			 std::vector<Position*> available_positions);

		Character(Character&&) = default;

		Character& operator = (Character&&) = default;

		void add_body(b2World* world, std::vector<Position*> available_positions);

		void set_move_state(Direction dir);

		Team get_team();

		void apply_impulses();

		bool has_enough_to_buy(std::unique_ptr<Weapon>& weapon_buy);

		bool has_optative_weapon();

		Weapon* drop_optative_weapon();

		void buy_weapon(std::unique_ptr<Weapon> weapon);

		void start_attacking();

		void change_weapon();

		b2Fixture* GetFixtureList();

		void add_kill_bonus();
		//void receive_damage(AttackInformation& attack);

		b2Vec2 get_pos();

		void take_damage(char points);

		char getLifePoints();

		void attack(AttackInformation& attack_info, std::list<Block>& blocks,
			 							std::map<char, Character>& characters);

		bool is_alive();
		void add_weapon(std::unique_ptr<Weapon> weapon);

		void stop_attacking();

		void set_angle(int angle);

		int get_angle();

		char get_life();

		int get_money();

		int get_ammo();

		char get_weapon_type();

		void block();

		void unblock();

		void reset_body(b2World* world, std::vector<Position*> available_positions);

		void change_team();

		int get_round_kills();
		int get_total_kills();
		char get_number_weapons();
		int get_glock_bullets();
		char get_optative_weapon_type();
		int get_optative_weapon_bullets();
		int get_optative_weapon_bullets_price(); 
		BuyState buy(char type_ammo); 
		int get_times_killed();
		~Character();
	private:
		Character(const Character &other) = delete;
		Character& operator=(const Character &other) = delete;

};

#endif
