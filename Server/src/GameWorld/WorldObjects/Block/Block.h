#ifndef _BLOCK_H
#define _BLOCK_H

#include "Configuration.h"
#include "../../libs/box2d/include/box2d/box2d.h"
#include "../../libs/box2d/include/box2d/b2_math.h"

class Block {
	b2Body* block_body;
	public:		
		Block(int x, int y, b2World* world);
		~Block();
		b2Fixture* GetFixtureList();
		Block(Block&&) = default;
        Block& operator = (Block&&) = default;
	private:
		Block(const Block &other) = delete;
		Block& operator=(const Block &other) = delete;
};


#endif
