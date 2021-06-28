#ifndef WEAPON_WHITE_H
#define WEAPON_WHITE_H

#include "Character.h"
#include "Weapon.h"
#include <iostream>

class WeaponWhite : public Weapon {
    public:
        WeaponWhite();

        void shoot(Character &character, uint16_t distance);

        ~WeaponWhite();
};

#endif
