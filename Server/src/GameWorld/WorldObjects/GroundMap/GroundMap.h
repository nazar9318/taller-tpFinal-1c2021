#ifndef _GROUND_MAP_H
#define _GROUND_MAP_H

#include <vector>
#include <list>
#include <string>
#include "Block.h"
#include "Position.h"
#include "Team.h"
#include "MapParser.h"
#include "../../libs/box2d/include/box2d/box2d.h"
#include "../../libs/box2d/include/box2d/b2_math.h"

class GroundMap {
		std::vector<Position> positions;
		int x_size;
		int y_size;

	public:
		GroundMap(const std::string& map_type);
		std::list<Block> fill_blocks(b2World* world);
		void get_limits(int& lenght, int& width);
		std::vector<Position*> get_blocks();
		std::vector<Position*> get_terrorist_zone();
		std::vector<Position*> get_counter_terrorist_zone();
		std::vector<Position*> get_bomb_zone();
		std::vector<Position*> get_zone(Team team);
		std::vector<Position*> get_drawable_positions();

		~GroundMap();
	
	private:
		void set_limits(b2World* world);
		GroundMap(const GroundMap &other) = delete;
		GroundMap& operator=(const GroundMap &other) = delete;
};


#endif
