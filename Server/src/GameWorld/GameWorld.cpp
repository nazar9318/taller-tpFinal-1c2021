#include "GameWorld.h"
#include <syslog.h>


GameWorld::GameWorld(const std::string& map_type):
			 number_players(0),ground(map_type), 
			 actual_team(Team::COUNTER_ENEMY), 
			 number_tics(0), number_round(0) {
	b2Vec2 gravity(0, 0);
	world = new b2World(gravity);
	blocks = ground.fill_blocks(world);
	weapons_in_ground = ground.fill_weapons();
	fase_type = FaseType::INITIAL_FASE;
}


void GameWorld::add_player_if_not_full(char id) {
	std::lock_guard<std::mutex> l(m);
	if (CF::players_allowed == number_players) 
		throw ExceptionInvalidCommand("La partida esta completa",
								 ServerError::MATCH_FULL); 
	syslog(LOG_INFO, "[%s:%i]: Por agregar el jugador con id %d"
					 " al GameWorld", __FILE__, __LINE__, id);
	Character character(actual_team, world,
					 ground.get_zone(actual_team), step_info);
	characters.insert({id, std::move(character)});
	actual_team = get_opposite(actual_team);
	number_players++;
	syslog(LOG_INFO, "[%s:%i]: Se agrego al jugador con id %d"
					 " al GameWorld", __FILE__, __LINE__, id);
}

void GameWorld::delete_player(char id) {
	std::lock_guard<std::mutex> l(m);
	characters.erase(id);
	number_players--;
}

Character& GameWorld::get_character(char id) {
	if (characters.find(id) == characters.end())
		throw Exception("No hay ningun jugador con ese nombre");
	return characters.at(id);
}


void GameWorld::start() {
	/* COMENTO PARA PROBAR SDL MAS FACIL. 
	if (number_players == 1) {
		throw ExceptionInvalidCommand("Debe haber al menos dos"
							"jugadores para empezar la partida",
								ServerError::NOT_ENOUGH_PLAYERS);
	}
	*/
	// asignar la bomba. 
}

std::vector<Position*> GameWorld::get_ground_info() {
	return ground.get_drawable_positions();
}

void GameWorld::get_limits(int& x, int& y) {
	ground.get_limits(x,y);
}


bool GameWorld::simulate_step() {
	step_info.set_type(fase_type);
	if (fase_type == FaseType::PLAYING) {
		simulate_playing_step();
		return true;
	} else if (fase_type == FaseType::INITIAL_FASE) {
		number_tics++;
		int wait = (int)(CF::time_preparation - number_tics * CF::step_time);
		step_info.set_waiting_time(wait);
		if (wait <= 0) {
			fase_type = FaseType::PLAYING;
		}
		return true;
	} else {
		number_round++;
		charge_stats();
		if (number_round == CF::number_rounds / 2) {
			change_teams();
		} else if (number_round == CF::number_rounds) {
			return false;
		}
		prepare_new_round();
		fase_type = FaseType::PLAYING;
	} 
	return true;
}


void GameWorld::change_teams() { 
}


void GameWorld::simulate_playing_step() { 
	for (auto it = characters.begin(); it != characters.end(); ++it) {
		it->second.apply_impulses();
		it->second.attack(it->first, blocks, characters);
	}
	
	
	world->Step(CF::step_time, CF::velocity_iterations,
								 CF::position_iterations);
	
	
	if (round_finished())
		fase_type = FaseType::END_ROUND;

}

bool GameWorld::round_finished() {
	// algun bando muerto. 
	// bomba explota, bomba desactivada
	return false;
}

void GameWorld::prepare_new_round() {

}

void GameWorld::charge_stats() {

}





StepInformation& GameWorld::get_step_info() { 
	return step_info;
}

GameWorld::~GameWorld() {
	delete world;
}
