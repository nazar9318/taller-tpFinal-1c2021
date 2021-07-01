#include "WeaponWhite.h"

WeaponWhite::WeaponWhite() :
			Weapon(0, CF::knife_damage_min,
			CF::knife_damage_max, CF::knife_max_distance,
			CF::knife_distance_penalty) {
}

void WeaponWhite::attack(AttackInformation& attack_info,
                    std::list<Block>& blocks, std::map<char,
                                Character>& characters) {
    /*if (activated && ammo >= 1) {
        attack_info.set_weapon(PositionType::GLOCK);
        std::map<char,Character>::iterator closest_char;
        float distance;
        float angle = attack_info.get_angle();
        bool is_character = find_closest_character(attack_info, blocks,
                                characters, angle, closest_char, distance);
        if (is_character) {
            char damage = calculate_damage(distance);
            if (damage > 0) {
                attack_info.set_receptor(TypeReceptor::CHARACTER);
                attack_info.add_receiver_id(closest_char->first);
                closest_char->second.receive_damage(attack_info);
            }   
        }
        deactivate();
        ammo -= 1;
   }
   */

}

char WeaponWhite::get_type(){
	return PositionType::KNIFE;
}
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
