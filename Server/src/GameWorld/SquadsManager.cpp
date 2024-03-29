#include "SquadsManager.h"
#include <syslog.h>
SquadsManager::SquadsManager(Team team):
			squad_one_wins(0), squad_two_wins(0),
			 		current_squad_one_team(team), 
			 		last_winner(1) {
	syslog(LOG_INFO, "[%s:%i]: El team 1 tiene team: %d"
				 , __FILE__, __LINE__, (int)team);
}

void SquadsManager::add_squad_character(Team team, char id) {
	if (team == current_squad_one_team) 
		ids_squad_one.push_back(id);
	else
		ids_squad_two.push_back(id);
	syslog(LOG_INFO, "[%s:%i]: id: %d es del team "
				 , __FILE__, __LINE__, (int)team);
}


void SquadsManager::add_win(Team team) {
	if (team == current_squad_one_team) {
		squad_one_wins++;
		last_winner = 1;
		syslog(LOG_INFO, "[%s:%i]: gano el team %d "
			 , __FILE__, __LINE__, (int)team);

	} else {
		squad_two_wins++;
		last_winner = 2;
	}
}


void SquadsManager::add_win(BombState bomb) {
	if (bomb == BombState::EXPLOTED)
		add_win(Team::TERRORIST);
	else if (bomb == BombState::DEACTIVATED)
		add_win(Team::COUNTER_ENEMY);
	else 
		throw Exception("Se recibe un BombState invalido en add_win");
}


void SquadsManager::change_teams() {
	current_squad_one_team = get_opposite(current_squad_one_team);
}


std::vector<char> SquadsManager::get_squads() {
	std::vector<char> squads;
	for (auto it = ids_squad_one.begin(); it != ids_squad_one.end(); it++) {
		squads.push_back(*it);
		squads.push_back((char)1);
	}
	for (auto it = ids_squad_two.begin(); it != ids_squad_two.end(); it++) {
		squads.push_back(*it);
		squads.push_back((char)2);
	}
	return squads;
}

void SquadsManager::get_wins(int& squad_one, int& squad_two) {
	squad_one = squad_one_wins;
	squad_two = squad_two_wins;
}

char SquadsManager::get_last_winner() {
	return last_winner;
}

Team SquadsManager::get_last_team_winner() {
	if (last_winner == 1) {
		syslog(LOG_INFO, "[%s:%i]: El last team winner es %d "
	 		, __FILE__, __LINE__, (int)current_squad_one_team);
		return current_squad_one_team;
	}
	return get_opposite(current_squad_one_team);
}

SquadsManager::~SquadsManager() {
}

