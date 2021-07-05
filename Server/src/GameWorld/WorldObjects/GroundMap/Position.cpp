#include "Position.h"

Position::Position(int column, int row, char type) :
	x(column), y(row), type_position(type), occupied(false) {
}

char Position::get_type() const {
	return type_position;
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

bool Position::is_ground() const {
	return ((type_position == PositionType::DUST) ||
			(type_position == PositionType::INFERNO) ||
			(type_position == PositionType::AZTEC));
}

bool Position::is_weapon() const {
	return ((type_position == PositionType::BOMB) ||
			(type_position == PositionType::KNIFE) ||
			(type_position == PositionType::AK47) ||
			(type_position == PositionType::M3) ||
			(type_position == PositionType::AWP));
}

bool Position::is_occupied() const {
	return occupied;
}

void Position::occupy() {
	occupied = true;
}

void Position::unoccupy() {
	occupied = false;
}

Position::~Position() {}
