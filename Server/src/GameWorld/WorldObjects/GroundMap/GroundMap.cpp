#include "GroundMap.h"
#include <string>
#include <utility>
#include <syslog.h>

GroundMap::GroundMap(const std::string& map_type) {
	MapParser parser;
	parser.build_positions(map_type, positions, x_size, y_size);
}

void GroundMap::get_limits(int& lenght, int& width) {
	lenght = x_size;
	width = y_size;
}

std::list<Block> GroundMap::fill_blocks(b2World* world) {
	std::list<Block> blocks;
	set_limits(world);
	for (auto it = positions.begin(); it != positions.end(); ++it) {
		if (it->is_block()){
		    Block block(it->get_x(), it->get_y(), world);
		    blocks.push_back(std::move(block));
		}
	}
	return blocks;
}


// agrega los limites en el mundo de box2d.
void GroundMap::set_limits(b2World* world) {
	b2Vec2 upper_left_vertex(0, 0);
	b2Vec2 upper_right_vertex(x_size, 0);
	b2Vec2 under_right_vertex(x_size, -y_size);
	b2Vec2 under_left_vertex(0, -y_size);


	b2BodyDef body_def;
	b2FixtureDef fixture_def;
	body_def.type = b2_staticBody;
	body_def.position.Set(0, 0); //sistema de referenca en 0, 0

	b2Body* static_body = world->CreateBody(&body_def);

	b2EdgeShape edge_shape;
	edge_shape.SetTwoSided(upper_left_vertex, upper_right_vertex );
	fixture_def.shape = &edge_shape;
	static_body->CreateFixture(&fixture_def);

	b2Body* static_body2 = world->CreateBody(&body_def);

	edge_shape.SetTwoSided(upper_left_vertex, under_left_vertex );
	fixture_def.shape = &edge_shape;
	static_body2->CreateFixture(&fixture_def);

	b2Body* static_body3 = world->CreateBody(&body_def);

	edge_shape.SetTwoSided(upper_right_vertex, under_right_vertex );
	fixture_def.shape = &edge_shape;
	static_body3->CreateFixture(&fixture_def);

	b2Body* static_body4 = world->CreateBody(&body_def);

	edge_shape.SetTwoSided(under_right_vertex, under_left_vertex );
	fixture_def.shape = &edge_shape;
	static_body4->CreateFixture(&fixture_def);
}


std::list<std::unique_ptr<Weapon>> GroundMap::fill_weapons() {
	std::list<std::unique_ptr<Weapon>> weapons;
	for (auto it = positions.begin(); it != positions.end(); ++it) {
		if (it->is_weapon()){
			std::unique_ptr<Weapon> weapon(
					WeaponFactory::create(it->get_type()));
			weapon->set_pos(it->get_x(), it->get_y());
			weapons.push_back(std::move(weapon));
		}
	}
	return weapons;
}




std::vector<Position*> GroundMap::get_terrorist_zone() {
	std::vector<Position*> terrorist_zone;
	for (auto it = positions.begin(); it != positions.end(); ++it) {
		if (it->is_terrorist_zone() && !it->is_occupied())
			terrorist_zone.push_back(&(*it));
	}
	return terrorist_zone;
}

std::vector<Position*> GroundMap::get_counter_terrorist_zone() {
	std::vector<Position*> counter_terrorists;
	for (auto it = positions.begin(); it != positions.end(); ++it) {
		if (it->is_counter_terrorist_zone() && !it->is_occupied())
			counter_terrorists.push_back(&(*it));
	}
	return counter_terrorists;
}

std::vector<Position*> GroundMap::get_zone(Team team) {
	if (team == Team::TERRORIST)
		return get_terrorist_zone();
	return get_counter_terrorist_zone();
}

std::vector<Position*> GroundMap::get_drawable_positions() {
	std::vector<Position*> drawable_zone;
	for (auto it = positions.begin(); it != positions.end(); ++it) {
		if (it->is_bomb_zone() || it->is_ground() || it->is_block())
			drawable_zone.push_back(&(*it));
	}
	return drawable_zone;
}

bool GroundMap::is_bomb_zone(b2Vec2& pos) {
	for (auto it = positions.begin(); it != positions.end(); ++it) {
		if ((it->is_bomb_zone()) &&
		 	(it->get_x() - CF::size_position / 2 <= pos.x) &&
		 	(it->get_x() + CF::size_position / 2 >= pos.x) && 
		 	(it->get_y() - CF::size_position / 2 <= pos.y) &&
		 	(it->get_y() + CF::size_position / 2 >= pos.y)) {
			syslog(LOG_INFO, "[%s:%i]: Zona de bomba en %d, %d "
					, __FILE__, __LINE__, (int)pos.x, (int)pos.y);
		 	return true;
		}
	}
	return false;
}

void GroundMap::unoccupy_spawns() {
	for (auto it = positions.begin(); it != positions.end(); ++it) {
		it->unoccupy();
	}
}

GroundMap::~GroundMap() {}
