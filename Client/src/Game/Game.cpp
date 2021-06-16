#include "Game.h"




Game::Game(ProtectedQueue<ModelEvent>& model,
		 ProtectedQueue<ClientEvent>& client, GameMap& game_map):
		  model_events(model), client_events(client), map(game_map) {
}
void Game::execute() {}

Game::~Game() {}
