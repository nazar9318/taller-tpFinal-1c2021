#include "weapon_automatic.h"
#include "character.h"
#include <random>
#include <chrono>

WeaponAutomatic::WeaponAutomatic() :
Weapon(CF::ak47_price, CF::ak47_damage_min, CF::ak47_damage_max),
accuracy(CF::ak47_accuracy), shoot_rate(CF::ak47_shoot_rate),
shoot_freq(CF::ak47_shoot_freq), distance_penalty(CF::ak47_distance_penalty),
ammo(CF::ak47_ammo), max_distance(CF::ak47_max_distance) {}

void WeaponAutomatic::shoot(Character &character, uint16_t distance) {
    if (distance <= this->max_distance && this->ammo > 0) {
        std::mt19937_64 rng;
        uint64_t seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
        std::seed_seq ss{uint32_t(seed & 0xffffffff), uint32_t(seed>>32)};
        rng.seed(ss);
        std::uniform_real_distribution<> unif(0,1);
        double rand = unif(rng);
        if (rand >= this->accuracy) {
            double damage_range = this->damage_max - this->damage_min;
            double damage = fmod((double)std::rand(), damage_range) + this->damage_min;
            character.takeDamage(damage - distance*distance_penalty);
            this->ammo -= this->shoot_rate;
        }
    }
    usleep(shoot_freq);
}

bool WeaponAutomatic::empty() { return (this->ammo == 0); }

WeaponAutomatic::~WeaponAutomatic() {}
