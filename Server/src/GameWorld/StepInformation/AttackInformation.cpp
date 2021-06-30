#include "AttackInformation.h"

AttackInformation::
AttackInformation(char id, Character* character, Team team):
					id_attacker(id), attacker(character),
									 team_attacked(team) {
}

float AttackInformation::get_angle() {
	return attacker->get_angle();
}

char AttackInformation::get_attacker_id() {
	return id_attacker;
}

void AttackInformation::add_receiver_id(char id) {
	id_receiver = id;
}

void AttackInformation::add_receiver(Character* attacked, bool takes_life) {
	receiver = attacked;
	is_dead = takes_life;
}

Team AttackInformation::get_team() {
	return team_attacked;
}


void AttackInformation::set_damage(char damage) {
	damage_weapon = damage;
}

char AttackInformation::get_damage() {
	return damage_weapon;
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


