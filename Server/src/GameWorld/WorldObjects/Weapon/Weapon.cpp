#include "Weapon.h"


Weapon::Weapon(unsigned int price, char damage_min, char damage_max,
		 unsigned int max_distance, float distance_penalty):
		price(price),
		damage_min(damage_min),
		damage_max(damage_max),
		distance_penalty(distance_penalty),
		activated(false) {
}

void Weapon::activate() {
	activated = true;
}

void Weapon::attack(AttackInformation& attack_info,
	 		std::list<Block>& blocks, std::map<char,
	 					 Character>& characters) {}


void Weapon::deactivate() {
	activated = false;
}

unsigned int Weapon::get_price() {
	return price;
}

Weapon::~Weapon() {
}
