#include "GameWorld.h"



GameWorld::GameWorld(): number_players_allowed(10), number_players(0) {}


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
GameWorld::~GameWorld() {}
