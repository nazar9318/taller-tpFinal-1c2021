#ifndef _BLOCK_H
#define _BLOCK_H


#include "../../libs/box2d/include/box2d/box2d.h"
#include "../../libs/box2d/include/box2d/b2_math.h"

class Block {
	b2Body* block_body;
	public:
		static int length; 
		
		Block(int x, int y, b2World* world);
		~Block();
		
		Block(Block&&) = default;
        Block& operator = (Block&&) = default;
	private:
		Block(const Block &other) = delete;
		Block& operator=(const Block &other) = delete;
};


#endif
