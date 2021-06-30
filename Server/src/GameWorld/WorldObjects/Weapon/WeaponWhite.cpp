#include "WeaponWhite.h"

WeaponWhite::WeaponWhite() : 
			Weapon(0, CF::knife_damage_min,
			CF::knife_damage_max, CF::knife_max_distance, 
			CF::knife_distance_penalty) {
}

void WeaponWhite::attack(AttackInformation& attack_info,
                    std::list<Block>& blocks, std::map<char,
                                 Character>& characters) {}


/*
void WeaponWhite::shoot(Character &character, uint16_t distance) {
    if (distance <= 1) {
        double damage_range = this->damage_max - this->damage_min;
        double damage = fmod((double)std::rand(), damage_range) + this->damage_min;
        character.takeDamage(damage);
    }
}
*/

WeaponWhite::~WeaponWhite() {}
