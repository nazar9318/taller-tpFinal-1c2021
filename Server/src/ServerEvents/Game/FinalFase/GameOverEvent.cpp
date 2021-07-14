#include "GameOverEvent.h"

GameOverEvent::GameOverEvent() {
	this->msg.push_back((char)ModelTypeEvent::GAME_OVER);
}

GameOverEvent::~GameOverEvent() {
}
