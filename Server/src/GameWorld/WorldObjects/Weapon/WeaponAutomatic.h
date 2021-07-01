#ifndef WEAPON_AUTOMATIC_H
#define WEAPON_AUTOMATIC_H

#include "Weapon.h"
#include "Character.h"
#include <random>
#include <chrono>

#include <iostream>
#include <random>
#include <unistd.h>

class WeaponAutomatic : public Weapon {
		float accuracy;
		unsigned int shoot_rate;
		unsigned int shoot_freq;
		unsigned int ammo;
		unsigned int number_tics;

	public:
		WeaponAutomatic();
		void attack(AttackInformation& attack_info,
			 		std::list<Block>& blocks, std::map<char,
			 					 Character>& characters);
		char calculate_damage(float distance);

		void deactivate();

	   // void shoot(Character &character, uint16_t distance);
		 char get_type();
		~WeaponAutomatic();

	private:

		bool empty();
};

#endif
