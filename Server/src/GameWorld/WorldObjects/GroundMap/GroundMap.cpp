#include "GroundMap.h"
#include <string>

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
	int box_lenght = Block::length;
	float half_box_length = (float)box_lenght / 2;
	b2Vec2 upper_left_vertex(-half_box_length,-half_box_length + y_size);
	b2Vec2 upper_right_vertex(-half_box_length + x_size, -half_box_length + y_size);
	b2Vec2 under_right_vertex(-half_box_length + x_size, -half_box_length);
	b2Vec2 under_left_vertex(-half_box_length, -half_box_length);

	
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





// Quedaria mas elegante con punteros a funciones.

std::vector<Position*> GroundMap::get_blocks() {
	std::vector<Position*> blocks;
	for (auto it = positions.begin(); it != positions.end(); ++it) {
		if (it->is_block())
			blocks.push_back(&(*it));
	}
	return blocks;
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

std::vector<Position*> GroundMap::get_bomb_zone() {
	std::vector<Position*> bomb_zone;
	for (auto it = positions.begin(); it != positions.end(); ++it) {
		if (it->is_bomb_zone())
			bomb_zone.push_back(&(*it));
	}
	return bomb_zone;
}

std::vector<Position*> GroundMap::get_zone(Team team) {
	if (team == Team::TERRORIST)
		return get_terrorist_zone();
	return get_counter_terrorist_zone();
}

std::vector<Position*> GroundMap::get_drawable_positions() {
	std::vector<Position*> drawable_zone;
	for (auto it = positions.begin(); it != positions.end(); ++it) {
		if (it->is_bomb_zone() || it->is_block() || it->is_weapon())
			drawable_zone.push_back(&(*it));
	}
	return drawable_zone;
}

GroundMap::~GroundMap() {}
