#include "WeaponPistol.h"
#include <syslog.h>


WeaponPistol::WeaponPistol() :
			Weapon(0, CF::glock_damage_min,
			CF::glock_damage_max, CF::glock_max_distance,
			CF::glock_distance_penalty, CF::glock_ammo,
			CF::glock_10_bullets_price, CF::glock_max_ammo),
			accuracy(CF::glock_accuracy) {
}


void WeaponPistol::attack(AttackInformation& attack_info,
					std::list<Block>& blocks, std::map<char,
								 Character>& characters) {
	if (activated && ammo >= 1) {
		attack_info.set_weapon(PositionType::GLOCK);
		std::map<char,Character>::iterator closest_char;
		double distance;
		int angle = attack_info.get_angle();
		bool is_character = find_closest_character(attack_info, blocks,
								characters, angle, closest_char, distance);
		if (is_character) {
			syslog(LOG_INFO, "[%s:%i]: Encuentra character pistol. "
				, __FILE__, __LINE__);
			char damage = calculate_damage(distance);
			if (damage > 0) {
				attack_info.add_receiver(closest_char->first,
											 &(closest_char->second));
				closest_char->second.take_damage(damage);
			}
		}
		ammo -= 1;
		deactivate();
   }
}

char WeaponPistol::calculate_damage(double distance) {
	std::mt19937_64 rng;
	uint64_t seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
	std::seed_seq ss{uint32_t(seed & 0xffffffff), uint32_t(seed>>32)};
	rng.seed(ss);
	std::uniform_real_distribution<> unif(0,1);
	double rand = unif(rng);
	if (rand < (accuracy * SIZE_POSITION) / distance) {
		double damage_range = damage_max - damage_min;
		double damage = fmod((double)std::rand(), damage_range) + damage_min;
		return (char)(damage - (distance > 1 ? distance * distance_penalty : 0));
	}
	return 0;
}



char WeaponPistol::get_type(){
	return PositionType::GLOCK;
}


bool WeaponPistol::empty() {
	return (ammo == 0);
}

WeaponPistol::~WeaponPistol() {}
