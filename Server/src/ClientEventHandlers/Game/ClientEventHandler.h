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
#include "BuyWeaponHandler.h"
#include "StopAttackingHandler.h"
#include "RotateHandler.h"

class ClientEventHandler{
		MoveHandler mover;
		StartAttackingHandler attacker; 
		GrabWeaponHandler graber; 
		DropWeaponHandler droper; 
		ChangeWeaponHandler changer; 
		BuyWeaponHandler buyier;
		StopAttackingHandler attack_stoper;
		RotateHandler rotator;
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
