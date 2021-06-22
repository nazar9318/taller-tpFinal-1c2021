#include "Position.h"


Position::Position(char column, char row, bool terrorist,
			 		bool counter_terrorist,
			 		bool bomb, bool is_block_zone):
	x(column), y(row), terrorist_zone(terrorist), 
	counter_terrorist_zone(counter_terrorist),
	bomb_zone(bomb), block(is_block_zone), occupied(false) {
} 


char Position::get_x() {
	return x;
}
char Position::get_y() {
	return y;
}
bool Position::is_terrorist_zone() {
	return terrorist_zone;
}
bool Position::is_counter_terrorist_zone() {
	return counter_terrorist_zone;
}
bool Position::is_bomb_zone() {
	return bomb_zone;
} 
bool Position::is_block() {
	return block;
}

bool Position::is_occupied() {
	return occupied;
}

void Position::occupy() {
	occupied = true;
}


Position::~Position() {}
