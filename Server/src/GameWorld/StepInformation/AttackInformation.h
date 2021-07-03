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
	Character* attacker;
	Team team_attacked;
	std::map<char, Character*> receivers;

	public:
		AttackInformation(char id, Character* attacker);

		bool is_valid_attack();

		std::vector<char> get_attack_message();

		std::list<Character*> get_killed_chars();

		float get_angle();

		char get_attacker_id();

		void add_receiver(char id, Character* attacked);

		void add_attacked_team(Team team);

		Team get_team();

		b2Vec2 get_init_pos();

		void set_weapon(PositionType weapon);

		AttackInformation(AttackInformation&&) = default;

		AttackInformation& operator = (AttackInformation&&) = default;

		~AttackInformation();
	private:
		AttackInformation(const AttackInformation &other) = delete;
		AttackInformation& operator=(const AttackInformation &other) = delete;
};

#endif
