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

		void set_pos(int x, int y);
		void get_pos(int& x, int& y);
		virtual char get_type();
		void deactivate();

		virtual void attack(AttackInformation& attack_info,
			 		std::list<Block>& blocks, std::map<char,
			 					 Character>& characters) = 0;

		unsigned int get_price();

		virtual ~Weapon() = 0;
};

#endif
