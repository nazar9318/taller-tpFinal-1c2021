#include "WeaponWhite.h"
#include <syslog.h>

WeaponWhite::WeaponWhite() :
			Weapon(0, CF::knife_damage_min,
			CF::knife_damage_max, CF::knife_max_distance,
			CF::knife_distance_penalty) {
}

void WeaponWhite::attack(AttackInformation& attack_info,
                    std::list<Block>& blocks, std::map<char,
                                Character>& characters) {
    // FALTA EL BARRIDO EN AREA. CORTA CON UN JUGADOR
    if (activated) {
        syslog(LOG_INFO, "[%s:%i]: Ataque del cuchi. "
                        , __FILE__, __LINE__);
        attack_info.set_weapon(PositionType::KNIFE);
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
   }
}

char WeaponWhite::get_type(){
	return PositionType::KNIFE;
}

char WeaponWhite::calculate_damage(float distance) {
    double damage_range = damage_max - damage_min;
    return (char)(fmod((double)std::rand(), damage_range) + damage_min);
}

WeaponWhite::~WeaponWhite() {}
