#include "GameWorld.h"



GameWorld::GameWorld(const std::string& map_type): number_players_allowed(10), number_players(0) {
	//crear clase para logica de cargado de mapas. 
}


void GameWorld::add_player_if_not_full(int id) {
	std::lock_guard<std::mutex> l(m);
	if (number_players_allowed == number_players) 
		throw ExceptionMatchFull("La partida esta completa"); 
	number_players++;
	// add_player(id);
}

void GameWorld::delete_player(int id) {
	std::lock_guard<std::mutex> l(m);
	// delete player
	number_players--;
}

void GameWorld::start() {}

// FALTA IMPLEMENTAR
std::vector<char> GameWorld::get_all_info() {
	std::vector<char> info; 
	std::string s = "Hello World!";
	std::copy(s.begin(), s.end(), std::back_inserter(info));
	return info;
}

void GameWorld::simulate_step() {}
std::vector<char> GameWorld::get_players_info() {
	std::vector<char> info; 
	std::string s = "Players Infooo!";
	std::copy(s.begin(), s.end(), std::back_inserter(info));
	return info;
}




GameWorld::~GameWorld() {}
