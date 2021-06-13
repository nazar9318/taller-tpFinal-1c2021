#ifndef WEAPON_H
#define WEAPON_H

class Player;

#include "player.hpp"
#include <iostream>

class Weapon {
    private:
        uint16_t price;
        uint16_t damage;
        uint16_t accuracy;
        uint16_t shoot_rate;
        uint16_t shoot_freq;
        uint16_t distance_penalty;
        bool automatic;

    public:
        Weapon(Weapon& other);

        Weapon(uint16_t price, uint16_t damage, uint16_t accuracy, uint16_t shoot_rate,
               uint16_t shoot_freq, uint16_t distance_penalty, bool automatic);

        /*acá habría que incluir la distancia entre jugadores*/
        void shoot(Player &player);

        uint16_t getPrice();

        ~Weapon();
};

#endif