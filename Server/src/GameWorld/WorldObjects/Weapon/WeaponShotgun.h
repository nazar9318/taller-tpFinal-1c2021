#ifndef WEAPON_SHOTGUN_H
#define WEAPON_SHOTGUN_H

#include "Character.h"
#include <chrono>
#include <iostream>
#include "Weapon.h"
#include <iostream>
#include <random>

class WeaponShotgun : public Weapon {
        float accuracy;
        unsigned int ammo;

    public:
        WeaponShotgun();
 		void attack(AttackInformation& attack_info,
		 		std::list<Block>& blocks, std::map<char,
		 				 Character>& characters);


        //void shoot(Character &character, uint16_t distance);

        ~WeaponShotgun();
    
    private:
        bool empty();
};

#endif
