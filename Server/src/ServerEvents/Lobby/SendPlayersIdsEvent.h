#ifndef _SEND_PLAYERS_ID_EVENT_H
#define _SEND_PLAYERS_ID_EVENT_H

#include "TypesOfEvents.h"
#include "Event.h"
#include "Player.h"
#include <list>
#include <string>
#include <map>


class SendPlayersIdsEvent: public Event {
	public:
		
		// map of (name, id_player) 
		// POST: El mensaje se construye como:
		//       msg[0] = type
		//       msg[1] = id
		//       msg[2] ... msg[i] = player_name
		//       ...
		SendPlayersIdsEvent(const std::map<char, Player*>& current_players);
		~SendPlayersIdsEvent();
	private:
		SendPlayersIdsEvent(const SendPlayersIdsEvent &other) = delete;
		SendPlayersIdsEvent& operator=(const SendPlayersIdsEvent &other) = delete;
};

#endif
