#ifndef _CLIENT_EVENT_HANDLER_H
#define _CLIENT_EVENT_HANDLER_H

#include <vector>

#include "GameWorld.h"
#include "TypesOfEvents.h"
#include "MoveHandler.h"
#include "StartAttackingHandler.h"
#include "GrabWeaponHandler.h"
#include "DropWeaponHandler.h"
#include "ChangeWeaponHandler.h"
#include "BuyArmourHandler.h"

class ClientEventHandler{
		MoveHandler mover;
		StartAttackingHandler attacker; 
		GrabWeaponHandler graber; 
		DropWeaponHandler droper; 
		ChangeWeaponHandler changer; 
		BuyArmourHandler buyier;
		GameWorld& world;
		
	public:
		ClientEventHandler(GameWorld& game_world); 

		void handle(Event& event); 

		~ClientEventHandler();

	private:
		ClientEventHandler(const ClientEventHandler &other) = delete;
		ClientEventHandler& operator=(const ClientEventHandler &other) = delete;
};

#endif
