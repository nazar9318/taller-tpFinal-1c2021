#ifndef _STEP_INFORMATION_H
#define _STEP_INFORMATION_H

#include <vector>
#include <map>
#include <string>
#include "Position.h"
#include "FaseType.h"
#include "Team.h"
#include "../../libs/box2d/include/box2d/box2d.h"
#include "../../libs/box2d/include/box2d/b2_math.h"
#include "AttackInformation.h"


class Character;
class StepInformation {
	// id, x, y
	std::map<char, std::pair<int, int>> positions;
	FaseType fase;
	std::map<char,Character>& characters;
	int waiting_time;
	std::list<AttackInformation> attacks;
	public:
		StepInformation(std::map<char,Character>& characters);
		void set_type(FaseType fase);
		FaseType get_type();
		std::vector<char> get_players_info();
		void set_waiting_time(int wait);
		int get_waiting_time();
		void clear();
		void add_position(char id, int x, int y);
		int get_wait();
		std::vector<char> get_players_init();
		void add_attack(AttackInformation attack_info);


		~StepInformation();
	private:
		StepInformation(const StepInformation &other) = delete;
		StepInformation& operator=(const StepInformation &other) = delete;
};

#endif
