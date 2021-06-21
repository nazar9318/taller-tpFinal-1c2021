#ifndef _POSITION_H
#define _POSITION_H

#include "ExceptionMatchFull.h"
#include <vector>

class Position {
		char x; 
		char y; 
		bool terrorist_zone;
		bool counter_terrorist_zone;
		bool bomb_zone; 
		bool block; 
	public:
		Position(char x, char y, bool terrorist,
			 		bool counter_terrorist,
			 		bool bomb, bool is_block_zone);
		char get_x();
		char get_y();
		bool is_terrorist_zone();
		bool is_counter_terrorist_zone();
		bool is_bomb_zone(); 
		bool is_block(); 
		~Position();
};


#endif
