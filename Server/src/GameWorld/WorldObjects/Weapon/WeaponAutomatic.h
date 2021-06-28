#ifndef WEAPON_AUTOMATIC_H
#define WEAPON_AUTOMATIC_H

#include "Weapon.h"
#include "Character.h"
#include <random>
#include <chrono>

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
        uint16_t max_distance;

    public:
        WeaponAutomatic();

        bool empty();

        void shoot(Character &character, uint16_t distance);

        ~WeaponAutomatic();
};

#endif