#ifndef WEAPON_WHITE_H
#define WEAPON_WHITE_H

#include "weapon.h"
#include <iostream>

//class Character;

class WeaponWhite : public Weapon {
    public:
        WeaponWhite(uint16_t price, uint16_t damage);

        void shoot(Character &character, uint16_t distance);

        ~WeaponWhite();
};

#endif
