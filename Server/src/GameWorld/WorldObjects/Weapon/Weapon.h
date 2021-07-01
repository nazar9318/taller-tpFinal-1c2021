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
		bool activated;
		unsigned int price;
		char damage_min;
		char damage_max;
		unsigned int max_distance;
		float distance_penalty;
		Weapon();

	public:
		Weapon(unsigned int price, char damage_min,char damage_max,
				 unsigned int max_distance, float distance_penalty);

		void activate();

		unsigned int get_price();
		void set_pos(int x, int y);
		void get_pos(int& x, int& y);
		virtual char get_type();
		virtual void deactivate();

		// POST: Retorna true si el mas cercano es un player. 
		bool find_closest_character(AttackInformation& attack_info,
							std::list<Block>& blocks,
							std::map<char, Character>& characters,
							float& angle,
							std::map<char,Character>::iterator& closest_char,
							float& distance);

		virtual void attack(AttackInformation& attack_info,
			 		std::list<Block>& blocks, std::map<char,
			 					 Character>& characters) = 0;


		virtual ~Weapon() = 0;
};

#endif
