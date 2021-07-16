#include "WeaponSniper.h"

#include <syslog.h>

WeaponSniper::WeaponSniper() :
			Weapon(CF::awp_price, CF::awp_damage_min,
			CF::awp_damage_max, CF::awp_max_distance,
			CF::awp_distance_penalty, CF::awp_ammo,
			CF::awp_10_bullets_price, CF::awp_max_ammo),
			accuracy(CF::awp_accuracy), retard_time(CF::awp_retard_time), 
			tics((unsigned)(retard_time / STEP_TIME)) {
}

void WeaponSniper::attack(AttackInformation& attack_info,
					std::list<Block>& blocks, std::map<char,
								 Character>& characters){
	if (activated && (ammo >= 1)) {
		attack_info.set_weapon(PositionType::AWP);
		std::map<char,Character>::iterator closest_char;
		double distance;
		int angle = attack_info.get_angle();
		bool is_character = find_closest_character(attack_info, blocks,
								characters, angle, closest_char, distance);
		if (is_character) {
			char damage = calculate_damage();
			if (damage > 0) {
				attack_info.add_receiver(closest_char->first,
											 &(closest_char->second));
				closest_char->second.take_damage(damage);
			}
		}
		deactivate();
		ammo -= 1;
		tics = 0;
	}
	tics++;
}


void WeaponSniper::activate() {
	if ((tics * STEP_TIME) >= retard_time) {
		activated = true;
	}
}

char WeaponSniper::get_type() {
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
