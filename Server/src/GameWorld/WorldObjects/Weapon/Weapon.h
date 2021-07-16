#ifndef WEAPON_H
#define WEAPON_H

class Character;
class AttackInformation;

#include <iostream>
#include <list>
#include <map>
#include "Team.h"
#include "Block.h"
#include "AttackInformation.h"
#include "Character.h"
#include "../../libs/box2d/include/box2d/box2d.h"
#include "../../libs/box2d/include/box2d/b2_math.h"
#include "TypesOfEvents.h"

class Weapon {
	protected:
		int pos_x;
		int pos_y;
		int ammo;
		int max_ammo;
		bool activated;
		int price;
		double damage_min;
		double damage_max;
		double max_distance;
		double distance_penalty;
		int ammo_price;
		Weapon();

	public:
		Weapon(int price, double damage_min, double damage_max,
				 double max_distance, double distance_penalty,
				 	int ammo, int ammo_price, int max_ammo);

		virtual void activate();

		int get_price();
		int get_ammo();
		void set_pos(int x, int y);
		void get_pos(int& x, int& y);
		virtual char get_type();
		virtual void deactivate();
		virtual bool add_ammo();
		virtual int get_ammo_price();
		// POST: Retorna true si el mas cercano es un player.
		bool find_closest_character(AttackInformation& attack_info,
							std::list<Block>& blocks,
							std::map<char, Character>& characters,
							int& angle,
							std::map<char,Character>::iterator& closest_char,
							double& distance);

		virtual void attack(AttackInformation& attack_info,
			 		std::list<Block>& blocks, std::map<char,
			 					 Character>& characters) = 0;

		virtual ~Weapon() = 0;
};

#endif
