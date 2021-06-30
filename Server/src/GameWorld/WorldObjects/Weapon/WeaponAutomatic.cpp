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
	float angle = attack_info.get_angle();
	b2Vec2 p1 = attack_info.get_init_pos();
	b2Vec2 p2 = p1 + max_distance * b2Vec2(sinf(angle), cosf(angle));
	
	bool is_static = true;
	b2RayCastInput input;
	input.p1 = p1;
	input.p2 = p2;
	input.maxFraction = 1;
	float closest_fraction = 1;
	for (auto it = blocks.begin(); it != blocks.end(); ++it) {
		for (b2Fixture* f = it->GetFixtureList(); f; f = f->GetNext()) {
			b2RayCastOutput output;
			if (!f->RayCast(&output, input, 0))
				continue;
			if (output.fraction < closest_fraction) {
				closest_fraction = output.fraction;
			}
		}
	}
	std::map<char,Character>::iterator closest_character;
	for (auto it = characters.begin(); it != characters.end(); ++it) {
		for (b2Fixture* f = it->second.GetFixtureList(); f;
													 f = f->GetNext()) {
			b2RayCastOutput output;
			if (!f->RayCast(&output, input, 0))
				continue;
			if (output.fraction < closest_fraction && 
					(it->first != attack_info.get_attacker_id())) {
				closest_fraction = output.fraction;
				is_static = false;
				closest_character = it;
			}            
		}
	}
	
	attack_info.set_receptor(TypeReceptor::NO_RECEPTOR);
	b2Vec2 intersection_point = p1 + closest_fraction * (p2 - p1);
	float distance = (intersection_point - p1).Length();
	if (is_static && (closest_fraction < 1)) {
		attack_info.set_receptor(TypeReceptor::STATIC);
	} else if (!is_static) {
		char damage = calculate_damage(distance);
		if (damage > 0) {
			attack_info.set_receptor(TypeReceptor::CHARACTER);
			attack_info.add_receiver_id(closest_character->first);
			closest_character->second.receive_damage(attack_info);
		}
	}
	attack_info.set_weapon(PositionType::AK47);
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
