#include "GameOverHandler.h"

GameOverHandler::GameOverHandler() {}

void GameOverHandler::handle(FaseType& fase, Event& event, GameMap& map) {
	fase = FaseType::ENDGAME;
}

GameOverHandler::~GameOverHandler() {}
