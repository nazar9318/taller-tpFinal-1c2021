#ifndef _CLIENT_EVENT_HANDLER_H
#define _CLIENT_EVENT_HANDLER_H

#include <vector>

#include "GameWorld.h"
#include "TypesOfEvents.h"
#include "MoveHandler.h"
#include "StartAttakingHandler.h"
//#include "GrabWeaponHandler.h"
//#include "DropWeaponHandler.h"
//#include "ExchangeWeaponHandler.h"
//#include "BuyArmourHandler.h"
//#include "QuitGameHandler.h"

class ClientEventHandler{
		MoveHandler mover;
		//StartAttakingHandler attacker; 
		//GrabWeaponHandler graber; 
		//DropWeaponHandler droper; 
		//ExchangeWeaponHandler exchanger; 
		//BuyArmourHandler buyier;
		//QuitGameHandler quiter; 
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
