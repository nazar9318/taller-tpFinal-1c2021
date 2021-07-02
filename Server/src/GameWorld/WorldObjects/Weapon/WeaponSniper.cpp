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
								 Character>& characters){
	if (activated && ammo >= 1) {
		attack_info.set_weapon(PositionType::AWP);
		std::map<char,Character>::iterator closest_char;
		float distance;
		float angle = attack_info.get_angle();
		bool is_character = find_closest_character(attack_info, blocks,
								characters, angle, closest_char, distance);
		if (is_character) {
			char damage = calculate_damage();
			if (damage > 0) {
				attack_info.set_receptor(TypeReceptor::CHARACTER);
				attack_info.add_receiver_id(closest_char->first);
				closest_char->second.receive_damage(attack_info);
			}   
		}
		deactivate();
		ammo -= 1;
   }
}

char WeaponSniper::get_type(){
	return PositionType::AWP;
}

char WeaponSniper::calculate_damage() {
	std::mt19937_64 rng;
	uint64_t seed = std::chrono::high_resolution_clock::now().
								time_since_epoch().count();
	std::seed_seq ss{uint32_t(seed & 0xffffffff), uint32_t(seed>>32)};
	rng.seed(ss);
	std::uniform_real_distribution<> unif(0,1);
	double rand = unif(rng);
	if (rand < accuracy) {
		return damage_max;
	}	
	return 0;
}



bool WeaponSniper::empty() {
	return (ammo == 0);
}

WeaponSniper::~WeaponSniper() {}
