#include "SendPlayersIdsEvent.h"
#include <syslog.h>

// map of (name, id_player) 
// POST: El mensaje se construye como:
//       msg[0] = type
//       msg[1] = id
//       msg[2] ... msg[i] = player_name
//       ...
SendPlayersIdsEvent::
SendPlayersIdsEvent(const std::map<char, Player*>& current_players) {
	this->msg.push_back(ModelTypeEvent::PLAYERS_ID_LIST);
	for (auto it = current_players.begin(); it != current_players.end(); ++it) {
		this->msg.push_back(it->first);
		std::string name = it->second->get_name();
		std::copy(name.begin(), name.end(), std::back_inserter(this->msg));
		this->msg.push_back('\0');
	}
	syslog(LOG_INFO, "[%s:%i]: Se construye evento de enviar"
					 " jugadores.", __FILE__, __LINE__);
}

SendPlayersIdsEvent::~SendPlayersIdsEvent() {
}
