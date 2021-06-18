#ifndef CHARACTER_H
#define CHARACTER_H

#include "weapon.h"
#include "weapon_white.h"
#include "weapon_manual.h"
#include "weapon_automatic.h"
#include "team.h"
#include <vector>
#include <iostream>

class Weapon;
class WeaponWhite;
class WeaponManual;
class WeaponAutomatic;

class Character {
    private:
        double life_points;
        uint16_t money;
        Team team;
        std::vector<Weapon*> weapons;
        Weapon* current_weapon;

    public:
        Character(double life_points, uint16_t money, Team team);

        void takeDamage(double points);

        void changeCurrentWeapon(uint16_t pos);

        void buy(Weapon *new_weapon);
        
        void grab(Weapon *new_weapon);

        void remove(Weapon *weapon);

        void take(uint16_t money);

        double getLifePoints();

        Team getTeam();

        /*acá habría que incluir la distancia entre jugadores*/
        void attack(Character &enemy, Team my_team, uint16_t distance);

        ~Character();
};

#endif
