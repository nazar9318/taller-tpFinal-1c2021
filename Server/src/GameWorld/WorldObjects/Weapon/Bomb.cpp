#include "Bomb.h"


Bomb::Bomb(): state(BombState::NORMAL),
			  clock_active(0), has_owner(false), 
			  clock_deactivate(0), pos(0.0, 0.0) {
}

void Bomb::add_owner(char id) {
	id_owner = id;
	has_owner = true;
	clock_active = 0;
	clock_deactivate = 0;
}

BombState Bomb::get_state() {
	return state;
}

bool Bomb::simulate_step() {
	switch (state) {
		case BombState::ACTIVATED:
		{
			clock_active++;
			if (clock_active * STEP_TIME >= CF::TIME_BOMB_EXPLOTE) {
				state = BombState::EXPLOTED;
				return true;
			}
			break;
		}                
		case BombState::ACTIVATING:
		{
			clock_active++;
			if (clock_active * STEP_TIME >= CF::TIME_BOMB_ACTIVATE) {
				state = BombState::ACTIVATED;
				clock_active = 0;
				has_owner = false;
			}   
			break; 
		}
		case BombState::DEACTIVATING: 
		{
			clock_active++;
			if (clock_active * STEP_TIME >= CF::TIME_BOMB_EXPLOTE)
				state = BombState::EXPLOTED;
			clock_deactivate++;
			if (clock_deactivate * STEP_TIME >= CF::TIME_BOMB_DEACTIVATE) {
				state = BombState::DEACTIVATED;	
				return true;
			}
			break;
		}
		case BombState::NORMAL:
		{
			clock_active = 0;
			clock_deactivate = 0;
			break;
		}
		case BombState::DEACTIVATED:
		{
			clock_active = 0;
			clock_deactivate = 0;
			return true;
			break;
		}
		case BombState::EXPLOTED:
		{
			clock_active = 0;
			clock_deactivate = 0;
			return true;
			break;
		}
	}
	return false;
}	


bool Bomb::activate(char id, b2Vec2& position) {
	if (has_owner && (id_owner == id) && (state == BombState::NORMAL)) {
		state = BombState::ACTIVATING;
		clock_active = 0;
		clock_deactivate = 0;
		pos = position;
		return true;
	}
	return false;
}

void Bomb::stop_activating(char id) {
	if (has_owner && (state == BombState::ACTIVATING) && (id_owner == id)) {
		state = BombState::NORMAL;
		clock_active = 0;
	}
}


bool Bomb::deactivate(Team team, char deactivator) {
	if ((!has_owner) && (state == BombState::ACTIVATED) && 
		 (team == Team::COUNTER_ENEMY)) {
		state = BombState::DEACTIVATING;
		has_owner = true;
		id_owner = deactivator;
		clock_deactivate = 0;
		return true;
	}
	return false;
}


void Bomb::stop_deactivating(char id) {
	if ((state == BombState::DEACTIVATING) && 
		 (id_owner == id)) {
		state = BombState::ACTIVATED;
		has_owner = false;
		clock_deactivate = 0;
	}
}

		
void Bomb::drop(char id, b2Vec2& position) {
	if (has_owner && (id == id_owner)) {
		has_owner = false;
		if ((state == BombState::NORMAL) || (state == BombState::ACTIVATING)) {
			pos = position;
			state = BombState::NORMAL;
			clock_active = 0;
		} else if (state == BombState::DEACTIVATING) {
			state = BombState::ACTIVATED;
			clock_deactivate = 0;
		}		
	}
}

bool Bomb::grab(char id, Team team) {
	if ((!has_owner) && (team == Team::TERRORIST)) {
		id_owner = id;
		clock_active = 0;
		has_owner = true;
		return true;
	}
	return false;
}

b2Vec2 Bomb::get_pos() {
	return pos;
}

void Bomb::restart() {
	state = BombState::NORMAL;
	clock_active = 0; 
	clock_deactivate = 0;
	has_owner = false;

}

// 2byte bombState

//-------------
// if es normaL:
	//bool has_owner
		//if(has_owner)
			// id
		//else 
			// 2 ints posicion

// if es ACTIVATING:
//      ID OWNER
//		CHAR PORCENTAJE 0, 10, 20, ..., 100

// if ACTIVATED
//     ID QUIEN ACTIVO
//     TIME EXPLOTE EN SEGUNDOS
//     POS X Y INT

// if DEACTIVATING
//     ID QUIEN DESACTIVANDO
//     CHAR PORCENTAJE 0, 10, 20, ..., 100
//     TIME EXPLOTE EN SEGUNDOS


std::vector<char> Bomb::get_info() {
	std::vector<char> info;
	info.push_back((char)state);
	if (state == BombState::NORMAL) {
		info.push_back((char)has_owner);
		if(has_owner) {
			info.push_back(id_owner);
		} else {
			int x = (int)pos.x;
			int y = (int)pos.y;
			info.push_back(*((char*)(&x)));
			info.push_back(*((char*)(&x) + 1));
			info.push_back(*((char*)(&x) + 2));
			info.push_back(*((char*)(&x) + 3));

			info.push_back(*((char*)(&y)));
			info.push_back(*((char*)(&y) + 1));
			info.push_back(*((char*)(&y) + 2));
			info.push_back(*((char*)(&y) + 3));
		}
	} else if (state == BombState::ACTIVATING) {
		info.push_back(id_owner);
		char percentage = (char)((clock_active * STEP_TIME * 100) /
										 CF::TIME_BOMB_ACTIVATE);
		info.push_back(percentage);
	} else if (state == BombState::ACTIVATED) {
		info.push_back(id_owner);
		char time_until_explote = (char)(CF::TIME_BOMB_EXPLOTE -
											 clock_active * STEP_TIME);
		info.push_back(time_until_explote);
		
		int x = (int)pos.x;
		int y = (int)pos.y;
		
		info.push_back(*((char*)(&x)));
		info.push_back(*((char*)(&x) + 1));
		info.push_back(*((char*)(&x) + 2));
		info.push_back(*((char*)(&x) + 3));

		info.push_back(*((char*)(&y)));
		info.push_back(*((char*)(&y) + 1));
		info.push_back(*((char*)(&y) + 2));
		info.push_back(*((char*)(&y) + 3));
	} else if (state == BombState::DEACTIVATING) {
		info.push_back(id_owner);
		char percentage = (char)((clock_deactivate * STEP_TIME * 100) /
										 CF::TIME_BOMB_DEACTIVATE);
		info.push_back(percentage);
		char time_until_explote = (char)(CF::TIME_BOMB_EXPLOTE -
											 clock_active * STEP_TIME);
		info.push_back(time_until_explote);
	}
	return info;
}


Bomb::~Bomb() {
}
