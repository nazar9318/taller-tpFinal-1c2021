#ifndef WEAPON_PISTOL_H
#define WEAPON_PISTOL_H

#include "Character.h"
#include <chrono>
#include "Weapon.h"
#include <iostream>
#include <random>

class WeaponPistol : public Weapon {
	private:
		float accuracy;
		unsigned int ammo;

	public:
		WeaponPistol();
		void attack(AttackInformation& attack_info,
			 		std::list<Block>& blocks, std::map<char,
			 				 Character>& characters);

		char get_type();
		~WeaponPistol();

	private:
		bool empty();
};

#endif
