#include "AttackInformation.h"

AttackInformation::
AttackInformation(char id, Character* character):
					id_attacker(id), attacker(character),
				 	weapon(PositionType::NO_WEAPON) {
}

bool AttackInformation::is_valid_attack() {
	return (weapon != PositionType::NO_WEAPON);
}

std::list<Character*> AttackInformation::get_killed_chars() {
	std::list<Character*> killed; 
	for (auto it = receivers.begin(); it != receivers.end(); ++it) {
		if (!it->second->is_alive()) {
			killed.push_back(it->second);
		}
	}
	return killed;
}


float AttackInformation::get_angle() {
	return attacker->get_angle();
}

char AttackInformation::get_attacker_id() {
	return id_attacker;
}

void AttackInformation::add_receiver(char id, Character* attacked) {
	receivers[id] = attacked;
}

void AttackInformation::add_attacked_team(Team team) {
	team_attacked = team;
}


Team AttackInformation::get_team() {
	return team_attacked;
}


void AttackInformation::set_weapon(PositionType weapon_type) {
	weapon = weapon_type;
}

b2Vec2 AttackInformation::get_init_pos() {
	return attacker->get_pos();
}


AttackInformation::~AttackInformation() {
}


