#include "WeaponWhite.h"
#include <syslog.h>

#define NO_AMMO -1

WeaponWhite::WeaponWhite() :
			Weapon(0, CF::knife_damage_min,
			CF::knife_damage_max, CF::knife_max_distance,
			CF::knife_distance_penalty, NO_AMMO, 0, 0) {
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
		double distance;
		int angle = attack_info.get_angle();
		syslog(LOG_INFO, "[%s:%i]: El angulo es de . "
			"%d. ", __FILE__, __LINE__, angle);
		bool is_character = find_closest_character(attack_info, blocks,
								characters, angle, closest_char, distance);
		if (is_character) {
			char damage = calculate_damage(distance);
			syslog(LOG_INFO, "[%s:%i]: Va a atacar a un character con damage"
			"%d. ", __FILE__, __LINE__, (int)damage);
			if (damage > 0) {
				attack_info.add_receiver(closest_char->first,
											 &(closest_char->second));
				closest_char->second.take_damage(damage);
			}
		}
		deactivate();
   }
}

char WeaponWhite::get_type(){
	return PositionType::KNIFE;
}

char WeaponWhite::calculate_damage(double distance) {
	double damage_range = damage_max - damage_min;
	return (char)(fmod((double)std::rand(), damage_range) + damage_min);
}

WeaponWhite::~WeaponWhite() {}
