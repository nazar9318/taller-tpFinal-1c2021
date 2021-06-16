#ifndef _LOBBY_H
#define _LOBBY_H

#include <string>
#include <iostream>
#include "ClientEvent.h"
#include "ModelEvent.h"
#include "ProtectedQueue.h"
#include "ProtectedQueue.h"
#include "GameMap.h"

class Lobby {
	ProtectedQueue<ModelEvent>& model_events;
	ProtectedQueue<ClientEvent>& client_events;
	GameMap& map;

	public:
		Lobby(ProtectedQueue<ModelEvent>& model_events,
		 ProtectedQueue<ClientEvent>& client_events, GameMap& map);
		
		// returns true if player is logged in. 
		bool launch();

		~Lobby();

	private:
		Lobby(const Lobby &other) = delete;
		Lobby& operator=(const Lobby &other) = delete;
};


#endif
