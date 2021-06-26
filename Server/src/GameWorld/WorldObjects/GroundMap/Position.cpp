#include "Position.h"

Position::Position(int column, int row, char type) :
	x(column), y(row), type_position(type), occupied(false) {
} 

int Position::get_x() const {
	return x;
}

int Position::get_y() const {
	return y;
}

bool Position::is_terrorist_zone() const {
	return type_position == PositionType::TERRORIST_SPAWN;
}

bool Position::is_counter_terrorist_zone() const {
	return type_position == PositionType::COUNTER_SPAWN;
}

bool Position::is_bomb_zone() const {
	return ((type_position == PositionType::BOMB_AREA_A) ||
			(type_position == PositionType::BOMB_AREA_B) ||
			(type_position == PositionType::BOMB_AREA_C));
}
 
bool Position::is_block() const {
	return ((type_position == PositionType::BOX_BLACK) ||
			(type_position == PositionType::BOX_BROWN) ||
			(type_position == PositionType::BOX_METAL) ||
			(type_position == PositionType::BOX_WOOD_METAL) ||
			(type_position == PositionType::BOX_WOOD));
}

bool Position::is_occupied() const {
	return occupied;
}

void Position::occupy() {
	occupied = true;
}


Position::~Position() {}
