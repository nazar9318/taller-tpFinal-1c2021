#include "GameStartedEvent.h"

GameStartedEvent::GameStartedEvent() {
	this->msg.push_back(ModelTypeEvent::GAME_STARTED);	
}

GameStartedEvent::~GameStartedEvent() {}
