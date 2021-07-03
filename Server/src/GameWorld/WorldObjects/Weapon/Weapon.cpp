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

bool Weapon::find_closest_character(AttackInformation& attack_info,
					 std::list<Block>& blocks,
					 std::map<char, Character>& characters,
					 float& angle,
					 std::map<char,Character>::iterator& closest_char,
					 float& distance) {
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
				closest_char = it;
			}
		}
	}
	b2Vec2 intersection_point = p1 + closest_fraction * (p2 - p1);
	distance = (intersection_point - p1).Length();
	return !is_static;
}





Weapon::~Weapon() {
}
