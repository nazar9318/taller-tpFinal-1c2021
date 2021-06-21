#ifndef _GROUND_MAP_H
#define _GROUND_MAP_H

#include <vector>
#include <list>
#include <string>
#include "Block.h"
#include "Position.h"
#include "../../libs/box2d/include/box2d/box2d.h"
#include "../../libs/box2d/include/box2d/b2_math.h"


class GroundMap {
		std::list<Position> positions;
		char x_size;
		char y_size;
	public:
		GroundMap(const std::string& map_type);
		void fill_blocks(b2World* world);

		void get_limits(char& lenght, char& width);
		std::list<Position> get_blocks();
		std::list<Position> get_terrorist_zone();
		std::list<Position> get_counter_terrorist_zone();
		std::list<Position> get_bomb_zone();
		~GroundMap();
	
	private:
		void set_limits(b2World* world);
		GroundMap(const GroundMap &other) = delete;
		GroundMap& operator=(const GroundMap &other) = delete;
};


#endif
