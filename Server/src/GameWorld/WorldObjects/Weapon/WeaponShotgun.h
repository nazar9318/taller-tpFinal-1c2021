#ifndef WEAPON_SHOTGUN_H
#define WEAPON_SHOTGUN_H

#include "Character.h"
#include <chrono>
#include <iostream>
#include "Weapon.h"
#include <iostream>
#include <random>

class Character;

class WeaponShotgun : public Weapon {
    private:
        float_t accuracy;
        float_t distance_penalty;
        uint16_t ammo;
        uint16_t max_distance;

    public:
        WeaponShotgun();

        bool empty();

        void shoot(Character &character, uint16_t distance);

        ~WeaponShotgun();
};

#endif
