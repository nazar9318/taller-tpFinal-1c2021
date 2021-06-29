#ifndef WEAPON_H
#define WEAPON_H


class Character;
class AttackInformation;


#include <iostream>
#include <list>
#include <map>
#include "Team.h"
#include "Block.h"
#include "AttackInformation.h"
#include "Character.h"
#include "../../libs/box2d/include/box2d/box2d.h"
#include "../../libs/box2d/include/box2d/b2_math.h"

class Weapon {

    protected:
        bool activated;
        


        uint16_t price;
        uint16_t damage_min;
        uint16_t damage_max;
        bool with_owner;

        Weapon() = default;

    public:
        Weapon(uint16_t price, uint16_t damage_min, uint16_t damage_max);

        void activate();

        void deactivate();

        virtual void attack(AttackInformation attack_info,
             std::list<Block>& blocks, std::map<char, Character>& characters);



        void beTaken();

        void beNotTaken();

        const bool taken();

        const uint16_t getPrice();

        virtual void shoot(Character &character, uint16_t distance) = 0;

        virtual ~Weapon() = 0;
};

#endif
