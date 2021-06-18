#ifndef _INITIATOR_H
#define _INITIATOR_H

#include <string>
#include <iostream>
#include "GameMap.h"
#include "Socket.h"
#include "GameWorldTypes.h"
#include "Protocol.h"

class Initiator {
	GameMap& map;

	public:
		Initiator(GameMap& map);
		
		// returns true if player is logged in. 
		bool launch(Socket& socket);

		~Initiator();

	private:
		Initiator(const Initiator &other) = delete;
		Initiator& operator=(const Initiator &other) = delete;
};


#endif