#include "SendBombStateEvent.h"

// Descripcion: Se envia el estado de la bomba luego de cada step.
// POST: El mensaje se construye con el tipo y el vector de informacion
SendBombStateEvent::SendBombStateEvent(std::vector<char> bomb_info) {
	this->msg.push_back((char)ModelTypeEvent::BOMB_INFO);
	std::copy(bomb_info.begin(),
				 bomb_info.end(), std::back_inserter(this->msg));
}

SendBombStateEvent::~SendBombStateEvent() {
}
