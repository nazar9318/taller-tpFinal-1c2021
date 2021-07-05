#ifndef BOMB_H
#define BOMB_H

#include "TypesOfEvents.h"
#include "Team.h"
#include "Configuration.h"
#include "../../libs/box2d/include/box2d/b2_math.h"

enum BombState: char {
	NORMAL,
	ACTIVATED, 
	DEACTIVATED, 
	ACTIVATING, 
	DEACTIVATING, 
	EXPLOTED
};

class Bomb {
	private:
		int clock_active;
		int clock_deactivate;
		BombState state;
		bool has_owner;
		char id_owner;
		b2Vec2 pos;

	public:
		Bomb();
		BombState get_state();
		void add_owner(char id);
		bool simulate_step();
		bool activate(char id, b2Vec2& pos);
		void stop_activating(char id);
		bool deactivate(Team team, char deactivator);
		void stop_deactivating(char id);
		void drop(char id, b2Vec2& pos);
		bool grab(char id, Team team);
		b2Vec2 get_pos();
		void restart();
		~Bomb();
};

#endif
