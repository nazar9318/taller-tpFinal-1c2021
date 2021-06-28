#include "WeaponShotgun.h"

WeaponShotgun::WeaponShotgun() :
Weapon(CF::m3_price, CF::m3_damage_min, CF::m3_damage_max),
accuracy(CF::m3_accuracy), distance_penalty(CF::m3_distance_penalty),
ammo(CF::m3_ammo), max_distance(CF::m3_max_distance) {}

void WeaponShotgun::shoot(Character &character, uint16_t distance) {
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

bool WeaponShotgun::empty() { return (this->ammo == 0); }

WeaponShotgun::~WeaponShotgun() {}
