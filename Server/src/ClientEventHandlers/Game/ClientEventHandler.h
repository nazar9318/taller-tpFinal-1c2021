#ifndef _CLIENT_EVENT_HANDLER_H
#define _CLIENT_EVENT_HANDLER_H

#include <vector>

#include "GameWorld.h"
#include "TypesOfEvents.h"
#include "MoveHandler.h"
#include "StartAttackingHandler.h"
#include "GrabWeaponHandler.h"
#include "ChangeWeaponHandler.h"
#include "BuyWeaponHandler.h"
#include "BuyBulletsHandler.h"
#include "StopAttackingHandler.h"
#include "RotateHandler.h"
#include "ActivateBombHandler.h"
#include "DeactivateBombHandler.h"
#include "StopActivatingBombHandler.h"
#include "StopDeactivatingBombHandler.h"

class ClientEventHandler{
		MoveHandler mover;
		StartAttackingHandler attacker; 
		GrabWeaponHandler graber; 
		ChangeWeaponHandler changer; 
		BuyWeaponHandler buyier_weapon;
		BuyBulletsHandler buyier_bullets;
		StopAttackingHandler attack_stoper;
		RotateHandler rotator;
		ActivateBombHandler bomb_activator;
		DeactivateBombHandler bomb_deactivator;
		StopActivatingBombHandler bomb_activator_stopper;
		StopDeactivatingBombHandler bomb_deactivator_stopper;
		GameWorld& world;

	public:
		ClientEventHandler(GameWorld& game_world); 

		void handle(Event& event); 

		~ClientEventHandler();

	private:
		void handle_init(Event& event);
		void handle_play(Event& event);


		ClientEventHandler(const ClientEventHandler &other) = delete;
		ClientEventHandler& operator=(const ClientEventHandler &other) = delete;
};

#endif
