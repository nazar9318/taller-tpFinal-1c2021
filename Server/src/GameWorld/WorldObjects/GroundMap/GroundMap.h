#ifndef _GROUND_MAP_H
#define _GROUND_MAP_H

#include <vector>
#include <syslog.h>
#include <list>
#include <string>
#include <tuple>
#include <memory>
#include "WeaponFactory.h"

#include "Weapon.h"
#include "Block.h"
#include "Position.h"
#include "Team.h"
#include "Configuration.h"
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
		std::vector<Position*> get_zone(Team team);
		std::vector<Position*> get_drawable_positions();
		std::list<std::unique_ptr<Weapon>> fill_weapons();
		bool is_bomb_zone(b2Vec2& pos);
		~GroundMap();

	private:
		void set_limits(b2World* world);
		std::vector<Position*> get_terrorist_zone();
		std::vector<Position*> get_counter_terrorist_zone();
		GroundMap(const GroundMap &other) = delete;
		GroundMap& operator=(const GroundMap &other) = delete;
};


#endif
