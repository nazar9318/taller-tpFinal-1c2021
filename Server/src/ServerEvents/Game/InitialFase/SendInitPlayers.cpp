#include "SendInitPlayersEvent.h"

// Descripcion: Envia la informacion inicial
//              de los jugadores antes de que comience la ronda. 
// POST: El mensaje se construye como el type + la informacion
//       que tenga el step al respecto.  
SendInitPlayersEvent::SendInitPlayersEvent(StepInformation& step) {
	this->msg.push_back((char)ModelTypeEvent::INITIAL_PLAYERS);
	std::vector<char> v = step.get_players_init();
	std::copy(v.begin(), v.end(), std::back_inserter(msg));
}

SendInitPlayersEvent::~SendInitPlayersEvent() {
}
