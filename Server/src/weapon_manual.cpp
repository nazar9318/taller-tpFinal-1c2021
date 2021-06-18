#include "weapon_manual.h"
#include "character.h"
#include <chrono>
#include <iostream>

WeaponManual::WeaponManual(uint16_t price, uint16_t damage, uint16_t max,
    float_t accuracy, float_t distance_penalty, uint16_t ammo) : 
    Weapon(price, damage, max),
accuracy(accuracy), distance_penalty(distance_penalty), ammo(ammo) {}

void WeaponManual::shoot(Character &character, uint16_t distance) {
    if (distance <= this->max_distance && this->ammo > 0) {
        std::mt19937_64 rng;
        uint64_t seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
        std::seed_seq ss{uint32_t(seed & 0xffffffff), uint32_t(seed>>32)};
        rng.seed(ss);
        std::uniform_real_distribution<> unif(0,1);
        double rand = unif(rng);
        if (rand < this->accuracy/distance) {
            character.takeDamage(this->damage - (distance > 1 ? distance*distance_penalty : 0));
            this->ammo--;
        }
    }
}

WeaponManual::~WeaponManual() {}
