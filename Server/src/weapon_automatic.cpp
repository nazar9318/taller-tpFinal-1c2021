#include "weapon_automatic.h"
#include "character.h"

WeaponAutomatic::WeaponAutomatic(uint16_t price, uint16_t damage, uint16_t max_distance,
    float_t accuracy, uint16_t shoot_rate, uint16_t shoot_freq,
    float_t distance_penalty, uint16_t ammo) : 
    Weapon(price, damage, max_distance),
accuracy(accuracy), shoot_rate(shoot_rate), shoot_freq(shoot_freq),
distance_penalty(distance_penalty), ammo(ammo) {}

void WeaponAutomatic::shoot(Character &character, uint16_t distance) {
    if (distance <= this->max_distance && this->ammo > 0) {
        uint16_t rand = (uint16_t)std::rand()/RAND_MAX;
        if (rand >= this->accuracy) {
            character.takeDamage(this->damage - distance*distance_penalty);
            this->ammo -= this->shoot_rate;
        }
    }
    usleep(shoot_freq);
}

