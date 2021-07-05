#include "Bomb.h"


Bomb::Bomb(): state(BombState::NORMAL),
			  clock_active(0), has_owner(false), 
			  clock_deactivate(0) {
}

void Bomb::add_owner(char id) {
	id_owner = id;
	has_owner = true;
	clock_active = 0;
	clock_deactivate = 0;
}

void Bomb::simulate_step() {
	switch (state) {
		case BombState::ACTIVATED:
		{
			clock_active++;
			if (clock_active * STEP_TIME >= CF::TIME_BOMB_EXPLOTE)
				state = BombState::EXPLOTED;
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
			if (clock_active * STEP_TIME >= CF::TIME_BOMB_DEACTIVATE)
				state = BombState::DEACTIVATED;	
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
			break;
		}
		case BombState::EXPLOTED:
		{
			clock_active = 0;
			clock_deactivate = 0;
			break;
		}
	}
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
	if (has_owner && (state = BombState::ACTIVATING) && (id_owner == id)) {
		state = BombState::NORMAL;
		clock_active = 0;
	}
}


bool Bomb::deactivate(Team team, char deactivator) {
	if ((state == BombState::ACTIVATED) && 
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

Bomb::~Bomb() {
}
