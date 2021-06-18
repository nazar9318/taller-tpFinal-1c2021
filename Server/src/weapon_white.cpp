#include "weapon_white.h"
#include "character.h"

WeaponWhite::WeaponWhite(uint16_t price, uint16_t damage) :
Weapon(price, damage, 1) {}

void WeaponWhite::shoot(Character &character, uint16_t distance) {
    if (distance <= this->max_distance) {
        character.takeDamage(this->damage);
    }
}

WeaponWhite::~WeaponWhite() {}
