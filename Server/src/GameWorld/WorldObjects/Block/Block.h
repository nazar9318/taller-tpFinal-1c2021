#ifndef _BLOCK_H
#define _BLOCK_H



class Block {
	public:
		Block() = default;
		~Block() = default;
		static int length; 
	private:
		Block(const Block &other) = delete;
		Block& operator=(const Block &other) = delete;
};


#endif
