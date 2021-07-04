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
		int shoot_rate;
		int shoot_freq;
		int number_tics;

	public:
		WeaponAutomatic();
		void attack(AttackInformation& attack_info,
			 		std::list<Block>& blocks, std::map<char,
			 					 Character>& characters);
		char calculate_damage(double distance);

		void deactivate();

	   // void shoot(Character &character, uint16_t distance);
		 char get_type();
		~WeaponAutomatic();

	private:

		bool empty();
};

#endif
