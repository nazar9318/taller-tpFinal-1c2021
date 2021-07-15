#include "SquadsManager.h"

SquadsManager::SquadsManager(Team team):
			squad_one_wins(0), squad_two_wins(0),
			 		current_squad_one_team(team) {
}

void SquadsManager::add_squad_character(Team team, char id) {
	if (team == current_squad_one_team) 
		ids_squad_one.push_back(id);
	else
		ids_squad_two.push_back(id);
}


void SquadsManager::add_win(Team team) {
	if (team == current_squad_one_team) 
		squad_one_wins++;
	else
		squad_two_wins++;
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


SquadsManager::~SquadsManager() {
}

