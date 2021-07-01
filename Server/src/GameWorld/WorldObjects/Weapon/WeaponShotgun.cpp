#include "WeaponShotgun.h"


WeaponShotgun::WeaponShotgun() :
			Weapon(CF::m3_price, CF::m3_damage_min,
			CF::m3_damage_max, CF::m3_max_distance,
			CF::m3_distance_penalty),
			accuracy(CF::m3_accuracy),
			ammo(CF::m3_ammo) {
}




// FALTA CORREGIR PARA QUE SEA EN CONO. 
void WeaponShotgun::attack(AttackInformation& attack_info,
					std::list<Block>& blocks, std::map<char,
								 Character>& characters){
	if (activated && ammo >= 1) {
		attack_info.set_weapon(PositionType::M3);
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
}

char WeaponShotgun::get_type(){
	return PositionType::M3;
}


char WeaponShotgun::calculate_damage(float distance) {
	std::mt19937_64 rng;
	uint64_t seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
	std::seed_seq ss{uint32_t(seed & 0xffffffff), uint32_t(seed>>32)};
	rng.seed(ss);
	std::uniform_real_distribution<> unif(0,1);
	double rand = unif(rng);
	if (rand < this->accuracy/distance) {
		double damage_range = this->damage_max - this->damage_min;
		double damage = fmod((double)std::rand(), damage_range) + this->damage_min;
		return (char)(damage - (distance > 1 ? distance*distance_penalty : 0));
	}	
	return 0;	
}


/*
void WeaponShotgun::shoot(Character &character, uint16_t distance) {
	if (distance <= this->max_distance && this->ammo > 0) {
		std::mt19937_64 rng;
		uint64_t seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
		std::seed_seq ss{uint32_t(seed & 0xffffffff), uint32_t(seed>>32)};
		rng.seed(ss);
		std::uniform_real_distribution<> unif(0,1);
		double rand = unif(rng);
		if (rand < this->accuracy/distance) {
			double damage_range = this->damage_max - this->damage_min;
			double damage = fmod((double)std::rand(), damage_range) + this->damage_min;
			character.takeDamage(damage - (distance > 1 ? distance*distance_penalty : 0));
			this->ammo--;
		}
	}
}
*/

bool WeaponShotgun::empty() {
	return (ammo == 0);
}

WeaponShotgun::~WeaponShotgun() {}
