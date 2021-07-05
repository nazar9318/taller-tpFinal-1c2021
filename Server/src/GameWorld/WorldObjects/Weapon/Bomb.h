#ifndef BOMB_H
#define BOMB_H

#include "TypesOfEvents.h"
#include "Team.h"
#include "Configuration.h"

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
		int pos_x;
		int pos_y;

	public:
		Bomb();
		void add_owner(char id);
		void simulate_step();
		bool activate(char id, int x, int y);
		void stop_activating(char id);
		bool deactivate(Team team, char deactivator);
		void stop_deactivating(char id);
		void drop(char id, int x, int y);
		bool grab(char id, Team team);
		~Bomb();
};

#endif
