#ifndef WEAPON_SNIPER_H
#define WEAPON_SNIPER_H

#include "Weapon.h"
#include "Character.h"
#include <chrono>
#include <iostream>
#include <iostream>
#include <random>

class WeaponSniper : public Weapon {
		float accuracy;
		unsigned int ammo;
	public:
		WeaponSniper();

		void attack(AttackInformation& attack_info,
	 			std::list<Block>& blocks, std::map<char,
						 Character>& characters);

		//void shoot(Character &character, uint16_t distance);
		char get_type();
		~WeaponSniper();

	private:
		bool empty();
};

#endif