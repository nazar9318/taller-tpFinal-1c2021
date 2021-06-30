#include "WeaponSniper.h"


WeaponSniper::WeaponSniper() :
            Weapon(CF::awp_price, CF::awp_damage_min,
            CF::awp_damage_max, CF::awp_max_distance, 
            CF::awp_distance_penalty),
            accuracy(CF::awp_accuracy),
            ammo(CF::awp_ammo) {
}

void WeaponSniper::attack(AttackInformation& attack_info,
                    std::list<Block>& blocks, std::map<char,
                                 Character>& characters){}


/*
void WeaponSniper::shoot(Character &character, uint16_t distance) {
    if (distance <= this->max_distance && this->ammo > 0) {
        std::mt19937_64 rng;
        uint64_t seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
        std::seed_seq ss{uint32_t(seed & 0xffffffff), uint32_t(seed>>32)};
        rng.seed(ss);
        std::uniform_real_distribution<> unif(0,1);
        double rand = unif(rng);
        if (rand < this->accuracy) {
            character.takeDamage(this->damage_max);
            this->ammo--;
        }
    }
}
*/

bool WeaponSniper::empty() {
    return (ammo == 0);
}

WeaponSniper::~WeaponSniper() {}
