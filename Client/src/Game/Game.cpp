#include "Game.h"




Game::Game(ProtectedQueue<ModelEvent>& model,
		 ProtectedQueue<ClientEvent>& client, GameMap& game_map):
		  model_events(model), client_events(client), map(game_map) {
}
void Game::execute() {
/*
	FrameLimiter frame_limiter;
	while (is_running) {
		handle_events();
		process_events();
		update();
		render();
		frame_limiter.sleep();
	}
*/
}

Game::~Game() {}
