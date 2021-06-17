#ifndef _INITIATOR_H
#define _INITIATOR_H

#include <string>
#include <iostream>
#include "ClientEvent.h"
#include "ModelEvent.h"
#include "ProtectedQueue.h"
#include "ProtectedQueue.h"
#include "GameMap.h"
#include "Socket.h"

class Initiator {
	ProtectedQueue<ModelEvent>& model_events;
	ProtectedQueue<ClientEvent>& client_events;
	GameMap& map;

	public:
		Initiator(ProtectedQueue<ModelEvent>& model_events,
		 ProtectedQueue<ClientEvent>& client_events, GameMap& map);
		
		// returns true if player is logged in. 
		bool launch(Socket& socket);

		~Initiator();

	private:
		Initiator(const Initiator &other) = delete;
		Initiator& operator=(const Initiator &other) = delete;
};


#endif
