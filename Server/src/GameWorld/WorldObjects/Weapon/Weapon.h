#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <list>
#include <map>
#include "Team.h"
#include "Block.h"
#include "StepInformation.h"
#include "../../libs/box2d/include/box2d/box2d.h"
#include "../../libs/box2d/include/box2d/b2_math.h"

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

        virtual void attack(Team team, b2Body* character_body,
             std::list<Block>& blocks, std::map<char, Character>& characters,
              StepInformation& step_info);

        const uint16_t getPrice();

        virtual void shoot(Character &character, uint16_t distance) = 0;

        virtual ~Weapon() = 0;
};

#endif
