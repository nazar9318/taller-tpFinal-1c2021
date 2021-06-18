#ifndef WEAPON_H
#define WEAPON_H

//#include "character.h"
#include <iostream>

class Character;

class Weapon {
    protected:
        uint16_t price;
        uint16_t damage;
        uint16_t max_distance;
        Weapon() = default;

    public:
        Weapon(uint16_t price, uint16_t damage, uint16_t max_distance);

        uint16_t getPrice();

        virtual void shoot(Character &character, uint16_t distance) = 0;

        ~Weapon();
};

#endif
