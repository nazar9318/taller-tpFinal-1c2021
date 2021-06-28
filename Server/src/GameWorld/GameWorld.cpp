#include "GameWorld.h"
#include <syslog.h>


GameWorld::GameWorld(const std::string& map_type):
			 number_players_allowed(10), number_players(0),
			 ground(map_type), actual_team(Team::COUNTER_ENEMY), 
			 number_tics(0), round_finished(false), number_round(0) {
	b2Vec2 gravity(0, 0);
	world = new b2World(gravity);
	blocks = ground.fill_blocks(world);
}


void GameWorld::add_player_if_not_full(char id) {
	std::lock_guard<std::mutex> l(m);
	if (number_players_allowed == number_players) 
		throw ExceptionMatchFull("La partida esta completa"); 
	syslog(LOG_INFO, "[%s:%i]: Por agregar el jugador con id %d"
					 " al GameWorld", __FILE__, __LINE__, id);
	Character character(actual_team, world, ground.get_zone(actual_team));
	characters.insert({id, std::move(character)});
	actual_team = get_opposite(actual_team);
	number_players++;
	syslog(LOG_INFO, "[%s:%i]: Se agrego al jugador con id %d"
					 " al GameWorld", __FILE__, __LINE__, id);
}

void GameWorld::delete_player(char id) {
	std::lock_guard<std::mutex> l(m);
	// delete player
	number_players--;
}

void GameWorld::start() {
	//chequear que haya al menos 2 jugadores. 
}

std::vector<Position*> GameWorld::get_ground_info() {
	return ground.get_drawable_positions();
}

void GameWorld::get_limits(int& x, int& y) {
	ground.get_limits(x,y);
}


bool GameWorld::simulate_step(float time_step) {
	
	//number_tics++;

	step_info.clear();
	for (auto it = characters.begin(); it != characters.end(); ++it) {
		it->second.apply_impulses();
		it->second.attack(blocks, characters, step_info);
	}
	
	int velocity_iterations = 8;
	int position_iterations = 3;
	world->Step(time_step, velocity_iterations, position_iterations);
	// round_finished = 
	// algun bando muerto. 
	// bomba explota, bomba desactivada
	for (auto it = characters.begin(); it != characters.end(); ++it) {
		//it->second.add_information(step_info);
	}
	if (round_finished) {
		number_round++;
		if (number_round == 10) {
			return false;
		}
	}
	return true;
}
std::vector<char> GameWorld::get_players_info() {
	std::vector<char> info; 
	std::string s = "Players Infooo!";
	std::copy(s.begin(), s.end(), std::back_inserter(info));
	return info;
}


const StepInformation& GameWorld::get_step_info() { 
	return step_info;
}

GameWorld::~GameWorld() {
	delete world;
}
