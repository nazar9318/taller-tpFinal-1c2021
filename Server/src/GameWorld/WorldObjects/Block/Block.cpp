#include "Block.h"

Block::Block(int x, int y, b2World* world){
	b2BodyDef block_body_def;
	block_body_def.type = b2_staticBody;
	block_body_def.position.Set(x, y); 
	block_body = world->CreateBody(&block_body_def);
		    
	b2PolygonShape box_shape;
	box_shape.SetAsBox((float)SIZE_POSITION/2, (float)SIZE_POSITION/2);
	b2FixtureDef block_fixture_def;
	block_fixture_def.shape = &box_shape;
	block_fixture_def.density = 1;
	block_body->CreateFixture(&block_fixture_def);
}

b2Fixture* Block::GetFixtureList() {
	return block_body->GetFixtureList();
}


Block::~Block(){

}
