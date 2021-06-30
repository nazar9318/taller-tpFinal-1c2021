#ifndef _ATTACK_INFORMATION_H
#define _ATTACK_INFORMATION_H

class Character;
class Weapon;
#include <vector>
#include <map>
#include <string>
#include "Team.h"
#include "TypesOfEvents.h"
#include "Character.h"

enum TypeReceptor: char {
	CHARACTER,
	STATIC, 
	NO_RECEPTOR
};

class AttackInformation {
	TypeReceptor type_attack;
	PositionType weapon;
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

		b2Vec2 get_init_pos();
		
		void set_receptor(TypeReceptor type);

		void set_weapon(PositionType weapon);

		AttackInformation& operator = (AttackInformation&&) = default;

		~AttackInformation();
	private:
		AttackInformation(const AttackInformation &other) = delete;
		AttackInformation& operator=(const AttackInformation &other) = delete;
};

#endif