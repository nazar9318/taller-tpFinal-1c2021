#ifndef WEAPON_SNIPER_H
#define WEAPON_SNIPER_H

#include "weapon.h"
#include <iostream>
#include <random>

class Character;

class WeaponSniper : public Weapon {
    private:
        float_t accuracy;
        float_t distance_penalty;
        uint16_t ammo;
        uint16_t max_distance;

    public:
        WeaponSniper();

        bool empty();

        void shoot(Character &character, uint16_t distance);

        ~WeaponSniper();
};

#endif
