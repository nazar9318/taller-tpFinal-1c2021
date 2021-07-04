#ifndef WEAPON_SHOTGUN_H
#define WEAPON_SHOTGUN_H

#include "Character.h"
#include <chrono>
#include <iostream>
#include "Weapon.h"
#include <iostream>
#include <random>

class WeaponShotgun : public Weapon {
        double accuracy;
        int ammo;

    public:
        WeaponShotgun();
 		void attack(AttackInformation& attack_info,
		 		std::list<Block>& blocks, std::map<char,
		 				 Character>& characters);


        //void shoot(Character &character, uint16_t distance);
        char calculate_damage(double distance);

        char get_type();
        ~WeaponShotgun();

    private:
        bool empty();
};

#endif
