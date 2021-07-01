#include "WeaponAutomatic.h"

WeaponAutomatic::WeaponAutomatic() :
			Weapon(CF::ak47_price, CF::ak47_damage_min,
			CF::ak47_damage_max, CF::ak47_max_distance,
			CF::ak47_distance_penalty),
			accuracy(CF::ak47_accuracy),
			shoot_rate(CF::ak47_shoot_rate),
			shoot_freq(CF::ak47_shoot_freq),
			ammo(CF::ak47_ammo) {
}

void WeaponAutomatic::attack(AttackInformation& attack_info,
			 std::list<Block>& blocks,
			  std::map<char, Character>& characters) {
	if (activated && ammo >= shoot_rate) {
		if (number_tics * CF::step_time >= shoot_freq) {
			attack_info.set_weapon(PositionType::AK47);
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
			number_tics = 0;
			ammo -= shoot_rate;
		}
		number_tics++;
	}
}



char WeaponAutomatic::calculate_damage(float distance) {
	std::mt19937_64 rng;
	uint64_t seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
	std::seed_seq ss{uint32_t(seed & 0xffffffff), uint32_t(seed>>32)};
	rng.seed(ss);
	std::uniform_real_distribution<> unif(0,1);
	double rand = unif(rng);
	if (rand >= this->accuracy) {
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

/*

void WeaponAutomatic::shoot(Character &character, uint16_t distance) {
	if (distance <= this->max_distance && this->ammo > 0) {
		std::mt19937_64 rng;
		uint64_t seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
		std::seed_seq ss{uint32_t(seed & 0xffffffff), uint32_t(seed>>32)};
		rng.seed(ss);
		std::uniform_real_distribution<> unif(0,1);
		double rand = unif(rng);
		if (rand >= this->accuracy) {
			double damage_range = this->damage_max - this->damage_min;
			double damage = fmod((double)std::rand(), damage_range) + this->damage_min;
			character.takeDamage(damage - distance*distance_penalty);
			this->ammo -= this->shoot_rate;
		}
	}
	usleep(shoot_freq);
}
*/

bool WeaponAutomatic::empty() {
	return (ammo == 0);
}

WeaponAutomatic::~WeaponAutomatic() {
}
