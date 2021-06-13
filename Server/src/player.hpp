#ifndef PLAYER_H
#define PLAYER_H

#include "weapon.hpp"
#include <vector>
#include <iostream>

enum Team {TERRORIST, COUNTER_ENEMY};

class Player {
    private:
        Team team;
        uint16_t life_points;
        uint16_t money;
        std::vector<Weapon*> weapons;
        Weapon* current_weapon;
        void buy(Weapon& new_weapon);
        void grab(Weapon *new_weapon);
        void remove(Weapon &weapon);
        void take(uint16_t money);

    public:
        Player(uint16_t life_points, uint16_t money, Team team);

        void takeDamage(uint16_t points);
        
        /*acá habría que incluir la distancia entre jugadores*/
        void attack(Player &enemy, Team my_team);

        ~Player();
};

#endif
