#include "AttackInformation.h"

AttackInformation::
AttackInformation(Character* character, Team team):
					attacker(character), team_attacked(team) {
}

float AttackInformation::get_angle() {
	return attacker->get_angle();
}


AttackInformation::~AttackInformation() {
}


