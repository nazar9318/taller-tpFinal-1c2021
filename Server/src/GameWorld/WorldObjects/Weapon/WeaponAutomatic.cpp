#include "WeaponAutomatic.h"

WeaponAutomatic::WeaponAutomatic() :
			Weapon(CF::ak47_price, CF::ak47_damage_min,
			CF::ak47_damage_max, CF::ak47_max_distance,
			CF::ak47_distance_penalty, CF::ak47_ammo),
			accuracy(CF::ak47_accuracy),
			shoot_rate(CF::ak47_shoot_rate),
			shoot_freq(CF::ak47_shoot_freq){
}


void WeaponAutomatic::attack(AttackInformation& attack_info,
			 std::list<Block>& blocks,
			  std::map<char, Character>& characters) {
	if (activated && ammo >= shoot_rate) {
		if (number_tics * STEP_TIME >= shoot_freq) {
			attack_info.set_weapon(PositionType::AK47);
			std::map<char, Character>::iterator closest_char;
			double distance;
			int angle = attack_info.get_angle();
			bool is_character = find_closest_character(attack_info, blocks,
									characters, angle, closest_char, distance);
			if (is_character) {
				for (int i = 0; i < shoot_rate; i++) {
					char damage = calculate_damage(distance);
					if (damage > 0) {
						attack_info.add_receiver(closest_char->first,
													 &(closest_char->second));
						closest_char->second.take_damage(damage);
					}
				}
			}
			number_tics = 0;
			ammo -= shoot_rate;
		}
		number_tics++;
	}
}



char WeaponAutomatic::calculate_damage(double distance) {
	std::mt19937_64 rng;
	uint64_t seed = std::chrono::high_resolution_clock::now().
										time_since_epoch().count();
	std::seed_seq ss{uint32_t(seed & 0xffffffff), uint32_t(seed>>32)};
	rng.seed(ss);
	std::uniform_real_distribution<> unif(0,1);
	double rand = unif(rng);
	if (rand >= accuracy / distance) {
		double damage_range = damage_max - damage_min;
		double damage = fmod((double)std::rand(), damage_range) + damage_min;
		return (char)(damage - distance * distance_penalty);
	}
	return 0;
}

void WeaponAutomatic::deactivate() {
	Weapon::deactivate();
	number_tics = 0;
}

char WeaponAutomatic::get_type(){
	return PositionType::AK47;
}


bool WeaponAutomatic::empty() {
	return (ammo == 0);
}

WeaponAutomatic::~WeaponAutomatic() {
}
