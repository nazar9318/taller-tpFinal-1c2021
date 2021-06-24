#include "Game.h"




Game::Game(ProtectedQueue<Event>& model,
		 ProtectedQueue<Event>& client):
		  model_events(model), client_events(client),
		  is_running(true) {
}




void Game::execute() {
	// GAME LOOP
	while (is_running) {
		handle_events();
		process_events();

		render();
	}

}


void Game::handle_events() {
		//poll de sdl hasta que no haya mas eventos.
		// ir agregando a la cola.
		// case KEY_UP:
			// case K:
				// std::unique_ptr<Event> event(new MoveEvent());
				// client_events.push(event);


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
