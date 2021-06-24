#include "GameWorld.h"



GameWorld::GameWorld(const std::string& map_type):
			 number_players_allowed(10), number_players(0),
			 ground(map_type), actual_team(Team::COUNTER_ENEMY) {
	b2Vec2 gravity(0, 0);
	world = new b2World(gravity);
	ground.fill_blocks(world);
}


void GameWorld::add_player_if_not_full(int id) {
	std::lock_guard<std::mutex> l(m);
	if (number_players_allowed == number_players) 
		throw ExceptionMatchFull("La partida esta completa"); 
	Character character(actual_team, world, ground.get_zone(actual_team));
	characters.insert({id, character});
	actual_team = get_opposite(actual_team);
	number_players++;
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
	std::string s = "Aca deberia ir toda la info del mapa!";
	std::copy(s.begin(), s.end(), std::back_inserter(info));
	return info;
}

bool GameWorld::simulate_step() {
	return true;
}
std::vector<char> GameWorld::get_players_info() {
	std::vector<char> info; 
	std::string s = "Players Infooo!";
	std::copy(s.begin(), s.end(), std::back_inserter(info));
	return info;
}




GameWorld::~GameWorld() {
	delete world;
}
