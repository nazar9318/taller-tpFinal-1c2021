#ifndef _ATTACK_INFORMATION_H
#define _ATTACK_INFORMATION_H

class Character;
class Weapon;
#include <vector>
#include <map>
#include <string>
#include "Team.h"
#include "Character.h"

class AttackInformation {
	char id_attacker;
	char id_receiver;
	Character* attacker;
	Team team_attacked;
	int x_attacker;
	int y_attacker;
	int x_receiver;
	int y_receiver;

	public:

		AttackInformation(Character* attacker, Team team_attacked);
		AttackInformation(AttackInformation&&) = default;
		float get_angle();
		AttackInformation& operator = (AttackInformation&&) = default;

		~AttackInformation();
	private:
		AttackInformation(const AttackInformation &other) = delete;
		AttackInformation& operator=(const AttackInformation &other) = delete;
};

#endif