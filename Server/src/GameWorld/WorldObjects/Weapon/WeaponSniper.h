#ifndef WEAPON_SNIPER_H
#define WEAPON_SNIPER_H

#include "Weapon.h"
#include "Character.h"
#include <chrono>
#include <iostream>
#include <iostream>
#include <random>

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
