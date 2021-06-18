#ifndef WEAPON_AUTOMATIC_H
#define WEAPON_AUTOMATIC_H

#include "weapon.h"
#include <iostream>
#include <random>
#include <unistd.h>

class Character;

class WeaponAutomatic : public Weapon {
    private:
        float_t accuracy;
        uint16_t shoot_rate;
        uint16_t shoot_freq;
        float_t distance_penalty;
        uint16_t ammo;

    public:
        WeaponAutomatic(uint16_t price, uint16_t damage, uint16_t max_distance,
                float_t accuracy, uint16_t shoot_rate, uint16_t shoot_freq,
                float_t distance_penalty, uint16_t ammo);

        void shoot(Character &character, uint16_t distance);

        void stopShooting();

        ~WeaponAutomatic();
};

#endif