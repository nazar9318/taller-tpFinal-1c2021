#ifndef _PLAYER_H
#define _PLAYER_H

#include "Socket.h"
#include "ProtectedQueue.h"
#include "ModelEvent.h"

class Player {

	public:
		Player(Socket& socket, int last_id, ProtectedQueue<ModelEvent>& to_process_events);
		~Player();
		void stop_running();

	private:
		Player(const Player &other) = delete;
		Player& operator=(const Player &other) = delete;
};


#endif
