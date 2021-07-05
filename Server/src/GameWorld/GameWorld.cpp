#include "GameWorld.h"
#include <syslog.h>


GameWorld::GameWorld(const std::string& map_type):
			 number_players(0),ground(map_type),
			 actual_team(Team::COUNTER_ENEMY),
			 number_tics(0), number_round(0), 
			 characters(), step_info(characters) {
	b2Vec2 gravity(0, 0);
	world = new b2World(gravity);
	blocks = ground.fill_blocks(world);
	weapons_in_ground = ground.fill_weapons();
	fase_type = FaseType::INITIAL_FASE;
}


void GameWorld::add_player_if_not_full(char id) {
	if (CF::players_allowed == number_players)
		throw ExceptionInvalidCommand("La partida esta completa",
								 ServerError::MATCH_FULL);
	Character character(actual_team, world,
					 ground.get_zone(actual_team));
	characters.insert({id, std::move(character)});
	actual_team = get_opposite(actual_team);
	number_players++;
	syslog(LOG_INFO, "[%s:%i]: Se agrego al jugador con id %d"
					 " al GameWorld", __FILE__, __LINE__, id);
}

void GameWorld::delete_player(char id) {
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
	// pongo esto asi no se rompe todo. 
	fase_type = FaseType::INITIAL_FASE;
	if (number_players > 1) 
		assign_bomb();
}

void GameWorld::assign_bomb() {
	int number_terrorist = number_players / 2;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(0, number_terrorist - 1);
	int bomb_terrorits = distrib(gen);
	bool bomb_not_assigned = true;
	auto it = characters.begin();
	int characters_checked = 0;
	while (bomb_not_assigned && (it != characters.end())) {
		if (it->second.get_team() == Team::TERRORIST) {
			if (characters_checked == bomb_terrorits) {
				bomb_not_assigned = false;
				bomb.add_owner(it->first);
				syslog(LOG_INFO, "[%s:%i]: Bomba es de %d "
			 					, __FILE__, __LINE__, (int)(it->first));
			}
			characters_checked++;
		}
		++it;
	}
}


std::vector<Position*> GameWorld::get_ground_info() {
	return ground.get_drawable_positions();
}

std::list<std::unique_ptr<Weapon>>& GameWorld::get_weapons_info() {
	return weapons_in_ground;
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
		int wait = (int)(CF::time_preparation - number_tics * STEP_TIME);
		step_info.set_waiting_time(wait);
		if (wait <= 0) {
			fase_type = FaseType::PLAYING;
			syslog(LOG_INFO, "[%s:%i]: Cambio de fase"
			 , __FILE__, __LINE__);
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


void GameWorld::handle_attack(std::map<char, Character>::iterator& it_attacker,
										 AttackInformation& attack_info) {
	if (attack_info.is_valid_attack()) {
		auto killed = attack_info.get_killed_chars();
		for (auto character = killed.begin();
									 character != killed.end(); ++character) {
			if (character->second->has_optative_weapon()) {
				Weapon* weapon = character->second->drop_optative_weapon();
				std::unique_ptr<Weapon> ground_weapon(weapon);
				weapons_in_ground.push_back(std::move(ground_weapon));
			}
			b2Vec2 pos = character->second->get_pos();
			bomb.drop(character->first, pos);
			it_attacker->second.add_kill_bonus();
		}
		step_info.add_attack(std::move(attack_info));
	}
}


void GameWorld::simulate_playing_step() {
	for (auto it = characters.begin(); it != characters.end(); ++it) {
		it->second.apply_impulses();
		AttackInformation attack_info(it->first, &(it->second));
		it->second.attack(attack_info, blocks, characters);
		handle_attack(it, attack_info);
	}
	world->Step(STEP_TIME, CF::velocity_iterations,
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


bool GameWorld::get_closest_weapon(b2Vec2 char_pos, Weapon** weapon) {
	int closest_distance = CF::max_distance_grab; 
	bool weapon_close_enough = false;
	std::list<std::unique_ptr<Weapon>>::iterator closest_weapon;
	for (auto it = weapons_in_ground.begin(); 
						it != weapons_in_ground.end(); ++it) {
		int x_weapon, y_weapon; 
		(*it)->get_pos(x_weapon, y_weapon);
		int distance = (int)((char_pos - b2Vec2(x_weapon, y_weapon)).Length());
		if (distance < closest_distance) {
			weapon_close_enough = true;
			closest_weapon = it;
		}
	}
	if (weapon_close_enough) {
		*weapon = closest_weapon->release();
		weapons_in_ground.erase(closest_weapon);
	}
	return weapon_close_enough;
}


void GameWorld::add_weapon(const b2Vec2& pos, Weapon* weapon) {
	std::unique_ptr<Weapon> ground_weapon(weapon);
	weapon->set_pos((int)pos.x, (int)pos.y);
	weapons_in_ground.push_back(std::move(ground_weapon));
}


StepInformation& GameWorld::get_step_info() {
	return step_info;
}

bool GameWorld::activate_bomb(char id, b2Vec2& pos) {
	return bomb.activate(id, pos);
}

bool GameWorld::deactivate_bomb(Team team, char id) {
	return bomb.deactivate(team, id);
}

void GameWorld::stop_activating_bomb(char id) {
	bomb.stop_activating(id);
}

void GameWorld::stop_deactivating_bomb(char id) {
	bomb.stop_deactivating(id);
}

bool GameWorld::grab_bomb(char id, Team team, b2Vec2& pos) {
	int distance = (bomb.get_pos() - pos).Length();
	if (distance <= CF::max_distance_grab)
		return bomb.grab(id, team);
	return false;
}


GameWorld::~GameWorld() {
	delete world;
}
