#include "Game.h"




Game::Game(ProtectedQueue<Event>& model,
		 ProtectedQueue<Event>& client, GameMap& game_map):
		  model_events(model), client_events(client), map(game_map),
		  is_running(true) {
}




void Game::execute() {
	FrameLimiter frame_limiter;
	// GAME LOOP
	while (is_running) {
		handle_events(); //
		process_events();

		render();
		frame_limiter.sleep();
	}

}


void Game::handle_events() {
	//poll de sdl hasta que no haya mas eventos. 
	// ir agregando a la cola. 



}

void Game::process_events() {
	bool queue_not_empty = true;
	int max_iterations = 15;//harcodeo, va en arch de config.
	int i = 0;
	while (queue_not_empty && max_iterations > i) {
		try {
			Event event = model_events.pop();
			handler.handle(event);
			i++;
		} catch(ExceptionEmptyQueue& e) {
			queue_not_empty = false;
		}
	}
}

void Game::update() {
	is_running = false;
}
void Game::render() {}


Game::~Game() {}
