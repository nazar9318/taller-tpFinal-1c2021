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

unsigned int Weapon::get_price() {
	return price;
}

void Weapon::set_pos(int x, int y) {
	pos_x = x;
	pos_y = y;
}
void Weapon::get_pos(int& x, int& y) {
	x = pos_x;
	y = pos_y;
}

char Weapon::get_type(){
	return 0;
}

void Weapon::attack(AttackInformation& attack_info,
	 		std::list<Block>& blocks, std::map<char,
	 					 Character>& characters) {}


void Weapon::deactivate() {
	activated = false;
}



Weapon::~Weapon() {
}
