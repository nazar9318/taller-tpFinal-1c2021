#include "Character.h"
#include "StepInformation.h"
#include <syslog.h>

StepInformation::
StepInformation(std::map<char,Character>& players):
						characters(players) {
}

int StepInformation::get_wait() {
	return waiting_time;
}

std::vector<char> StepInformation::get_reason_finish() {
	return reason_finish;
}

void StepInformation::add_team_eliminated(Team team) {
	reason_finish.clear();
	reason_finish.push_back(ReasonFinish::TEAM_ELIMINATED);
	reason_finish.push_back((char)team);
}

void StepInformation::add_finish(BombState state) {
	reason_finish.clear();
	reason_finish.push_back(ReasonFinish::BOMB_ENDED);
	reason_finish.push_back((char)state);
}

std::vector<char> StepInformation::get_players_init() {
	std::vector<char> v;
	for (auto it = characters.begin(); it != characters.end(); ++it) {
		v.push_back(it->first); // ID
		Team team = it->second.get_team();
		v.push_back((char)team);

		int money = it->second.get_money();
		v.push_back(*((char*)(&money)));
		v.push_back(*((char*)(&money) + 1));
		v.push_back(*((char*)(&money) + 2));
		v.push_back(*((char*)(&money) + 3));

		char number_of_weapons = it->second.get_number_weapons();
		v.push_back(number_of_weapons);

		int glock_bullets = it->second.get_glock_bullets();
		v.push_back(*((char*)(&glock_bullets)));
		v.push_back(*((char*)(&glock_bullets) + 1));
		v.push_back(*((char*)(&glock_bullets) + 2));
		v.push_back(*((char*)(&glock_bullets) + 3));

		if (number_of_weapons == 3) {
			v.push_back(it->second.get_optative_weapon_type());
			int bullets = it->second.get_optative_weapon_bullets();
			v.push_back(*((char*)(&bullets)));
			v.push_back(*((char*)(&bullets) + 1));
			v.push_back(*((char*)(&bullets) + 2));
			v.push_back(*((char*)(&bullets) + 3));

			int bullets_price = it->second.get_optative_weapon_bullets_price();
			v.push_back(*((char*)(&bullets_price)));
			v.push_back(*((char*)(&bullets_price) + 1));
			v.push_back(*((char*)(&bullets_price) + 2));
			v.push_back(*((char*)(&bullets_price) + 3));
		}
	}
	return v;
}

void StepInformation::add_attack(AttackInformation attack_info) {
	attacks.push_back(std::move(attack_info));
}

std::vector<char> StepInformation::get_attacks(){
	std::vector<char> msg;
	msg.push_back((char)attacks.size());

	for (auto it = attacks.begin(); it != attacks.end(); ++it) {
		std::vector<char> attack = it->get_attack_message();
		std::copy(attack.begin(), attack.end(), std::back_inserter(msg));
	}
	attacks.clear();
	return msg;
}

void StepInformation::set_type(FaseType fase_type) {
	fase = fase_type;
}

FaseType StepInformation::get_type() {
	return fase;
}

void StepInformation::set_waiting_time(int wait) {
	waiting_time = wait;
}

int StepInformation::get_waiting_time() {
	return waiting_time;
}

void StepInformation::add_position(char id, int x, int y) {
	std::pair<int, int> pos(x, y * (-1));
	positions[id] = pos;
}

std::vector<char> StepInformation::get_players_info() {
	std::vector<char> players_info;
	for (auto it = characters.begin(); it != characters.end(); ++it) {
		players_info.push_back(it->first); // ID
		b2Vec2 pos = it->second.get_pos();

		int x = (int)pos.x; // POS_X
		players_info.push_back(*((char*)(&x)));
		players_info.push_back(*((char*)(&x) + 1));
		players_info.push_back(*((char*)(&x) + 2));
		players_info.push_back(*((char*)(&x) + 3));

		int y = (int)pos.y * (-1); // POS_Y
		players_info.push_back(*((char*)(&y)));
		players_info.push_back(*((char*)(&y) + 1));
		players_info.push_back(*((char*)(&y) + 2));
		players_info.push_back(*((char*)(&y) + 3));

		int angle = it->second.get_angle();
		players_info.push_back(*((char*)(&angle)));
		players_info.push_back(*((char*)(&angle) + 1));
		players_info.push_back(*((char*)(&angle) + 2));
		players_info.push_back(*((char*)(&angle) + 3));

		players_info.push_back((it->second).get_life());

		int money = it->second.get_money();
		players_info.push_back(*((char*)(&money)));
		players_info.push_back(*((char*)(&money) + 1));
		players_info.push_back(*((char*)(&money) + 2));
		players_info.push_back(*((char*)(&money) + 3));

		//WEAPON
		players_info.push_back(it->second.get_weapon_type());

		//BULLETS
		int ammo = it->second.get_ammo();
		players_info.push_back(*((char*)(&ammo)));
		players_info.push_back(*((char*)(&ammo) + 1));
		players_info.push_back(*((char*)(&ammo) + 2));
		players_info.push_back(*((char*)(&ammo) + 3));

	}

	return players_info;
}

std::vector<char> StepInformation::get_stats() {
	std::vector<char> stats;
	// tiene ((kills_round, id), kills_total)
	std::set<std::tuple<int, char>> ordered_by_round_kills;
	for (auto it = characters.begin(); it != characters.end(); ++it) {
		std::tuple<int, char> key(
				std::make_tuple(it->second.get_round_kills(), it->first));
		ordered_by_round_kills.insert(key);
	}

	for (auto it = ordered_by_round_kills.begin();
								 it != ordered_by_round_kills.end(); ++it) {
		char id = std::get<1>(*it);
		Character& character = characters.at(id);
		stats.push_back(id);
		int kills_round = std::get<0>(*it);
		int kills_total = character.get_total_kills();
		int money = character.get_money();
		int times_killed = character.get_times_killed();

		stats.push_back(*((char*)(&kills_round)));
		stats.push_back(*((char*)(&kills_round) + 1));
		stats.push_back(*((char*)(&kills_round) + 2));
		stats.push_back(*((char*)(&kills_round) + 3));

		stats.push_back(*((char*)(&kills_total)));
		stats.push_back(*((char*)(&kills_total) + 1));
		stats.push_back(*((char*)(&kills_total) + 2));
		stats.push_back(*((char*)(&kills_total) + 3));

		stats.push_back(*((char*)(&money)));
		stats.push_back(*((char*)(&money) + 1));
		stats.push_back(*((char*)(&money) + 2));
		stats.push_back(*((char*)(&money) + 3));

		stats.push_back(*((char*)(&times_killed)));
		stats.push_back(*((char*)(&times_killed) + 1));
		stats.push_back(*((char*)(&times_killed) + 2));
		stats.push_back(*((char*)(&times_killed) + 3));
	}
	return stats;
}



/*
	id tipo_compra successful, plata #armas bullets_arma2 arma3 bullets
	...
*/

void StepInformation::add_buy(char id,
				 ClientTypeEvent bullets_or_weapon, BuyState state) {
	syslog(LOG_INFO, "[%s:%i]: Por agregar compra de %d "
					 , __FILE__, __LINE__, (int)id);

	buys.push_back(id);
	buys.push_back((char)bullets_or_weapon);
	buys.push_back((char)state);

	Character& character = characters.at(id);

	int money = character.get_money();
	buys.push_back(*((char*)(&money)));
	buys.push_back(*((char*)(&money) + 1));
	buys.push_back(*((char*)(&money) + 2));
	buys.push_back(*((char*)(&money) + 3));

	char number_of_weapons = character.get_number_weapons();
	buys.push_back(number_of_weapons);

	int glock_bullets = character.get_glock_bullets();
	buys.push_back(*((char*)(&glock_bullets)));
	buys.push_back(*((char*)(&glock_bullets) + 1));
	buys.push_back(*((char*)(&glock_bullets) + 2));
	buys.push_back(*((char*)(&glock_bullets) + 3));

	if (number_of_weapons == 3) {
		buys.push_back(character.get_optative_weapon_type());
		int bullets = character.get_optative_weapon_bullets();
		buys.push_back(*((char*)(&bullets)));
		buys.push_back(*((char*)(&bullets) + 1));
		buys.push_back(*((char*)(&bullets) + 2));
		buys.push_back(*((char*)(&bullets) + 3));

		int bullets_price = character.get_optative_weapon_bullets_price();
		buys.push_back(*((char*)(&bullets_price)));
		buys.push_back(*((char*)(&bullets_price) + 1));
		buys.push_back(*((char*)(&bullets_price) + 2));
		buys.push_back(*((char*)(&bullets_price) + 3));
	}
}

bool StepInformation::any_buys() {
	return (buys.size() > 0);
}

std::vector<char> StepInformation::get_buys() {
	std::vector<char> buys_send(std::move(buys));
	buys.clear();
	return buys_send;
}


StepInformation::~StepInformation() {}
