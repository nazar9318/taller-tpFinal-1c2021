#include "weapon_pistol.h"
#include "character.h"
#include <chrono>

WeaponPistol::WeaponPistol() :
Weapon(CF::glock_price, CF::glock_damage_min, CF::glock_damage_max),
accuracy(CF::glock_accuracy), distance_penalty(CF::glock_distance_penalty),
ammo(CF::glock_ammo), max_distance(CF::glock_max_distance) {}

void WeaponPistol::shoot(Character &character, uint16_t distance) {
    if (distance <= this->max_distance && this->ammo > 0) {
        std::mt19937_64 rng;
        uint64_t seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
        std::seed_seq ss{uint32_t(seed & 0xffffffff), uint32_t(seed>>32)};
        rng.seed(ss);
        std::uniform_real_distribution<> unif(0,1);
        double rand = unif(rng);
        if (rand < this->accuracy/distance) {
            double damage_range = this->damage_max - this->damage_min;
            double damage = fmod((double)std::rand(), damage_range) + this->damage_min;
            character.takeDamage(damage - (distance > 1 ? distance*distance_penalty : 0));
            this->ammo--;
        }
    }
}

bool WeaponPistol::empty() { return (this->ammo == 0); }

WeaponPistol::~WeaponPistol() {}
