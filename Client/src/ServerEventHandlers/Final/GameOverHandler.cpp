#include "GameOverHandler.h"

GameOverHandler::GameOverHandler() {

}

void GameOverHandler::handle(FaseType& fase, Event& event, GameMap& map) {
	// manejarlo. Una idea podria ser agregar una fase mas que se llame
	// GameOverFase y le seteas a eso la fase. Entonces tendria que salir del
	// while del cliente y empezar un nuevo while no cierre la ventana que se 
	// quede donde esta. 
}

GameOverHandler::~GameOverHandler() {

}
