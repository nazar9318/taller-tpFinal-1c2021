#include "Weapon.h"
#define PI 3.14159265


Weapon::Weapon(int price, double damage_min, double damage_max,
		 	double max_distance, double distance_penalty, int ammo):
		price(price),
		damage_min(damage_min),
		damage_max(damage_max),
		max_distance(max_distance),
		distance_penalty(distance_penalty),
		activated(false),
		ammo(ammo) {
}

void Weapon::activate() {
	activated = true;
}

int Weapon::get_price() {
	return price;
}

int Weapon::get_ammo() {
	return ammo;
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
					 int& angle,
					 std::map<char,Character>::iterator& closest_char,
					 double& distance) {
	b2Vec2 p1 = attack_info.get_init_pos();
	b2Vec2 direction(cos(angle * PI / 180), sin(angle * PI / 180));
	b2Vec2 p2 = p1 + max_distance * direction;
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
	if (!is_static && attack_info.get_team() == closest_char->second.get_team()) {
		return true;
	}
	return false;
}





Weapon::~Weapon() {
}
