#ifndef _POSITION_H
#define _POSITION_H

#include "ExceptionMatchFull.h"
#include "WeaponType.h"
#include "TypesOfEvents.h"
#include <vector>

class Position {
		int x;
		int y;
		bool occupied;
		char type_position;

	public:
		Position(int x, int y, char type_position);
		
		int get_x() const;
		int get_y() const;
		bool is_terrorist_zone() const;
		bool is_counter_terrorist_zone() const;
		bool is_bomb_zone() const;
		bool is_block() const;
		bool is_occupied() const;
		void occupy();
		~Position();
};


#endif
