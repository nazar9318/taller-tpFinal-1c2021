#ifndef _MODEL_EVENT_HANDLER_H
#define _MODEL_EVENT_HANDLER_H

#include <vector>
#include "TypesOfEvents.h"
#include "Event.h"
#include "Exception.h"

#include "GameMap.h"
#include "AttackEffect.h"
#include "ClientBomb.h"
#include "FaseType.h"
#include "ReciveMapHandler.h"
#include "ReciveWeaponHandler.h"
#include "ReceivePlayingStepHandler.h"
#include "ReceiveInitStepHandler.h"
#include "ReceiveInitPlayersHandler.h"
#include "ReceiveBombStateHandler.h"
#include "ReceiveStatsHandler.h"
#include "ReceiveSquadsHandler.h"
#include "ReceiveFinalStateHandler.h"
#include "ReceiveAttacksHandler.h"
#include "ReceiveInitConfigsHandler.h"
#include "ReceiveBuysHandler.h"
#include "SoundHandler.h"
#include "InitialPhase.h"

class ModelEventHandler {
	private:
		ReciveMapHandler recive_map;
		ReciveWeaponHandler recive_weapons;
		ReceivePlayingStepHandler playing_step;
		ReceiveInitStepHandler init_step;
		ReceiveInitPlayersHandler player_init;
		ReceiveBombStateHandler bomb_state;
		ReceiveStatsHandler stats;
		ReceiveSquadsHandler squads_receiver;
		ReceiveFinalStateHandler final_state_receiver;
		ReceiveAttacksHandler attacks_receiver;
		ReceiveInitConfigsHandler configs;
		ReceiveBuysHandler buys;
		SoundHandler sound_handler;

	public:
		ModelEventHandler();

		// POST: Retorna la fase actual
		void handle(FaseType& fase, Event& event, GameMap& map, ClientBomb& bomb,
			 					AttackEffect& attack_effects, InitialPhase& initial_phase);

		~ModelEventHandler();

	private:
		ModelEventHandler(const ModelEventHandler &other) = delete;
		ModelEventHandler& operator=(const ModelEventHandler &other) = delete;
};

#endif
