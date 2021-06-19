#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>

class Character;

class Weapon {
    protected:
        uint16_t price;
        uint16_t damage_min;
        uint16_t damage_max;
        bool with_owner;
        Weapon() = default;

    public:
        Weapon(uint16_t price, uint16_t damage_min, uint16_t damage_max);

        void beTaken();

        void beNotTaken();

        const bool taken();

        const uint16_t getPrice();

        virtual void shoot(Character &character, uint16_t distance) = 0;

        ~Weapon();
};

#endif
