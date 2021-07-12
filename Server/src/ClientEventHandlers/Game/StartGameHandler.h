#ifndef START_GAME_HANDLER_H
#define START_GAME_HANDLER_H

#include <map>
#include <memory>
#include <list>
#include "TypesOfEvents.h"
#include "SendFullMapEvent.h"
#include "SendWeaponsEvent.h"
#include "Player.h"
#include "GameWorld.h"
#include "GameStartedEvent.h"
#include "Position.h"
#include "SendSquadsEvent.h"

class StartGameHandler{
	public:
		StartGameHandler();

		// PRE: El evento es del tipo START_GAME
		// POST: Inicia la partida en el mundo y le envia a todos
		//       los jugadores la informacion del estado del mundo.
		void handle(Event& event, std::map<char, Player*>& players,
							 GameWorld& game_world);
		~StartGameHandler();
};

#endif
