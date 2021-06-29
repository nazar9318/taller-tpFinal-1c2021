#ifndef WEAPON_PISTOL_H
#define WEAPON_PISTOL_H

#include "Character.h"
#include <chrono>
#include "Weapon.h"
#include <iostream>
#include <random>

class WeaponPistol : public Weapon {
    private:
        float_t accuracy;
        float_t distance_penalty;
        uint16_t ammo;
        uint16_t max_distance;

    public:
        WeaponPistol();

        bool empty();

        void shoot(Character &character, uint16_t distance);

        ~WeaponPistol();
};

#endif