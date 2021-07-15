#ifndef _SQUADS_MANAGER_H
#define _SQUADS_MANAGER_H

#include <list>
#include <vector>
#include "Team.h"
#include "BombState.h"
#include "Exception.h"


class SquadsManager {
		std::list<char> ids_squad_one;
		std::list<char> ids_squad_two;
		int squad_one_wins;
		int squad_two_wins;
		Team current_squad_one_team;
	public:
		SquadsManager(Team current_squad_one_team);
		void add_squad_character(Team team, char id);
		void change_teams();
		void add_win(Team team);
		void add_win(BombState bomb);
		std::vector<char> get_squads();
		void get_wins(int& squad_one, int& squad_two);
		~SquadsManager();
};


#endif