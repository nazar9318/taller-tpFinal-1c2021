#ifndef WEAPON_MANUAL_H
#define WEAPON_MANUAL_H

#include "weapon.h"
#include <iostream>
#include <random>

class Character;

class WeaponManual : public Weapon {
    private:
        float_t accuracy;
        float_t distance_penalty;
        uint16_t ammo;

    public:
        WeaponManual(uint16_t price, uint16_t damage, uint16_t max_distance, 
                float_t accuracy, float_t distance_penalty, uint16_t ammo);

        void shoot(Character &character, uint16_t distance);

        ~WeaponManual();
};

#endif
