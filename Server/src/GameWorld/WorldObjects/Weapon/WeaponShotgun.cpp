#include "WeaponShotgun.h"


WeaponShotgun::WeaponShotgun() :
			Weapon(CF::m3_price, CF::m3_damage_min,
			CF::m3_damage_max, CF::m3_max_distance,
			CF::m3_distance_penalty, CF::m3_ammo,
			CF::m3_10_bullets_price, CF::m3_max_ammo),
			accuracy(CF::m3_accuracy), 
			angle_covered((int)(CF::m3_angle_covered % 360)){
}

void WeaponShotgun::attack(AttackInformation& attack_info,
					std::list<Block>& blocks, std::map<char,
								 Character>& characters){
	if (activated && ammo >= 1) {
		attack_info.set_weapon(PositionType::M3);
		for (int i = ((-1) * angle_covered / 2); i < (angle_covered / 2); i++) {
			std::map<char,Character>::iterator closest_char;
			double distance;
			int angle = attack_info.get_angle() + i;
			bool is_character = find_closest_character(attack_info, blocks,
									characters, angle, closest_char, distance);
			if (is_character) {
				char damage = calculate_damage(distance);
				if (damage > 0) {
					attack_info.add_receiver(closest_char->first,
												 &(closest_char->second));
					closest_char->second.take_damage(damage);
				}
			}
		}
		deactivate();
		ammo -= 1;
   }
}

char WeaponShotgun::get_type(){
	return PositionType::M3;
}


char WeaponShotgun::calculate_damage(double distance) {
	std::mt19937_64 rng;
	uint64_t seed = std::chrono::high_resolution_clock::now().
										time_since_epoch().count();
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

bool WeaponShotgun::empty() {
	return (ammo == 0);
}

WeaponShotgun::~WeaponShotgun() {}
