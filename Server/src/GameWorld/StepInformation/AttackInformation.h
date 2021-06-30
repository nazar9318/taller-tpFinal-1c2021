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
	char id_receiver;
	char id_attacker;
	char damage_weapon;
	Character* attacker;
	Character* receiver;
	Team team_attacked;
	int x_attacker;
	int y_attacker;
	int x_receiver;
	int y_receiver;
	bool is_dead;

	public:

		AttackInformation(char id, Character* attacker, Team team_attacked);
		
		AttackInformation(AttackInformation&&) = default;
		
		float get_angle();

		char get_attacker_id();
		
		void add_receiver_id(char id);

		void add_receiver(Character* attacked, bool is_dead);

		b2Vec2 get_init_pos();
		
		void set_receptor(TypeReceptor type);

		void set_weapon(PositionType weapon);

		Team get_team();


		void set_damage(char damage);

		char get_damage();



		AttackInformation& operator = (AttackInformation&&) = default;

		~AttackInformation();
	private:
		AttackInformation(const AttackInformation &other) = delete;
		AttackInformation& operator=(const AttackInformation &other) = delete;
};

#endif