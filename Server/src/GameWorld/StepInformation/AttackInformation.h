#ifndef _ATTACK_INFORMATION_H
#define _ATTACK_INFORMATION_H

#include <vector>
#include <map>
#include <string>


class AttackInformation {
	char id_attacker;
	char id_receiver;
	int x_attacker;
	int y_attacker;
	int x_receiver;
	int y_receiver;

	public:
		AttackInformation();
		~AttackInformation();
	private:
		AttackInformation(const AttackInformation &other) = delete;
		AttackInformation& operator=(const AttackInformation &other) = delete;
};

#endif