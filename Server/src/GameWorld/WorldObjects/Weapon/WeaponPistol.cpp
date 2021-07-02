#include "WeaponPistol.h"


WeaponPistol::WeaponPistol() :
			Weapon(CF::glock_price, CF::glock_damage_min,
			CF::glock_damage_max, CF::glock_max_distance,
			CF::glock_distance_penalty),
			accuracy(CF::glock_accuracy),
			ammo(CF::glock_ammo) {
}


void WeaponPistol::attack(AttackInformation& attack_info,
					std::list<Block>& blocks, std::map<char,
								 Character>& characters) {
	if (activated && ammo >= 1) {
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
		ammo -= 1;
		deactivate();
   }
}

char WeaponPistol::calculate_damage(float distance) {
	std::mt19937_64 rng;
	uint64_t seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
	std::seed_seq ss{uint32_t(seed & 0xffffffff), uint32_t(seed>>32)};
	rng.seed(ss);
	std::uniform_real_distribution<> unif(0,1);
	double rand = unif(rng);
	if (rand < accuracy / distance) {
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
