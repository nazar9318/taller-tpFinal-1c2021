#ifndef _PLAYER_H
#define _PLAYER_H

class Player {

	public:
		Player();
		~Player();

	private:
		Player(const Player &other) = delete;
		Player& operator=(const Player &other) = delete;
};


#endif
