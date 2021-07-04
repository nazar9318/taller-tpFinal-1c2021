#ifndef WEAPON_WHITE_H
#define WEAPON_WHITE_H

#include "Weapon.h"
#include "Character.h"
#include <iostream>

class WeaponWhite : public Weapon {
    public:
        WeaponWhite();

		void attack(AttackInformation& attack_info,
			 		std::list<Block>& blocks, std::map<char,
			 					 Character>& characters);

        char get_type();
        //void shoot(Character &character, uint16_t distance);
        char calculate_damage(double distance);

        ~WeaponWhite();
};

#endif
