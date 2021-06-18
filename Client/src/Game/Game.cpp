#include "Game.h"




Game::Game(ProtectedQueue<ModelEvent>& model,
		 ProtectedQueue<ClientEvent>& client, GameMap& game_map):
		  model_events(model), client_events(client), map(game_map),
		  is_running(true) {
}
void Game::execute() {
	FrameLimiter frame_limiter;
	// GAME LOOP
	while (is_running) {
		handle_events(); //
		process_events();
		update();
		render();
		frame_limiter.sleep();
	}

}


void Game::handle_events() {}
void Game::process_events() {}
void Game::update() {
	is_running = false;
}
void Game::render() {}


Game::~Game() {}
