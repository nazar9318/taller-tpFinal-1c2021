#ifndef _POSITION_H
#define _POSITION_H

#include "ExceptionMatchFull.h"
#include <vector>

enum WEAPON_TYPE {SHOTGUN, AUTOMATIC, PISTOL, SNIPER, NONE};

class Position {
		char x;
		char y;
		bool terrorist_zone;
		bool counter_terrorist_zone;
		bool bomb_zone; 
		bool block;
		WEAPON_TYPE weapon;
		bool occupied;

	public:
		Position(char x, char y, bool terrorist,
			 		bool counter_terrorist, WEAPON_TYPE weapon,
			 		bool bomb, bool is_block_zone);
		char get_x() const;
		char get_y() const;
		bool is_terrorist_zone() const;
		bool is_counter_terrorist_zone() const;
		bool is_bomb_zone() const;
		bool is_block() const;
		bool is_occupied() const;
		void occupy();
		~Position();
};


#endif
