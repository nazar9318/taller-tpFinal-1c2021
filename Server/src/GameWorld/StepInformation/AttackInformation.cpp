#include "AttackInformation.h"

AttackInformation::
AttackInformation(Character* character, Team team):
					attacker(character), team_attacked(team) {
}

float AttackInformation::get_angle() {
	return attacker->get_angle();
}

void AttackInformation::set_receptor(TypeReceptor type) {
	type_attack = type;
}

void AttackInformation::set_weapon(PositionType weapon_type) {
	weapon = weapon_type;
}

b2Vec2 AttackInformation::get_init_pos() {
	return attacker->get_pos();
}


AttackInformation::~AttackInformation() {
}


