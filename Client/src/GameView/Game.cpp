#include "Game.h"

Game::Game(ProtectedQueue<Event>& model,
		 ProtectedQueue<std::unique_ptr<Event>>& client):
		  model_events(model), client_events(client),
		  is_running(true), window("Counter 2d", 800, 600, false), renderer(window), map(renderer){
}



void Game::execute() {
	try{
		loadMedia();
		while (is_running) {
			is_running = handle_events();
			process_events();

			render();
		}
	} catch(std::exception& e){
		syslog(LOG_CRIT, "[%s:%i]: Exception: %s", __FILE__, __LINE__,  e.what());
	}

}

void Game::loadMedia(){
	map.loadMedia();
}

void Game::render(){

	map.renderGround();
	renderer.presentScreen();
}



bool Game::handle_events() {

	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
			return false;
			break;
			case SDL_KEYDOWN:
			handle_key_press(event);
			break;
			case SDL_KEYUP:
			handle_key_release(event);
			break;
			case SDL_MOUSEBUTTONDOWN:
			handle_click(event);
			break;
			case SDL_MOUSEBUTTONUP:
			handle_unclick(event);
			break;
			case SDL_MOUSEMOTION:
			handle_mouse_motion();
			break;
			default:
			break;
		}
	}
	return true;
}

void Game::handle_key_press(SDL_Event& event){
	switch (event.key.keysym.sym) {
		case SDLK_w:
			//
			break;
		case SDLK_a:
			break;
		case SDLK_d:
			break;
		case SDLK_s:
			break;
		case SDLK_SPACE:
			break;
	}
}

void Game::handle_key_release(SDL_Event& event) {
	switch (event.key.keysym.sym) {
		case SDLK_w:
		break;
		case SDLK_a:
		break;
		case SDLK_d:
		break;
		case SDLK_s:
		break;
		case SDLK_SPACE:
		break;
	}
}

void Game::handle_click(SDL_Event& event) {
	switch (event.button.button) {
		case SDL_BUTTON_RIGHT:
			break;
		case SDL_BUTTON_LEFT:
			// std::unique_ptr<Event> event(new MoveEvent());
			// client_events.push(event);
			break;
	}
}

void Game::handle_unclick(SDL_Event& event) {
	switch (event.button.button) {
		case SDL_BUTTON_RIGHT:
		break;
		case SDL_BUTTON_LEFT:
		break;
	}
}

void Game::handle_mouse_motion() {
	/* code */
}

void Game::process_events() {
	bool queue_not_empty = true;
	int max_iterations = 15;//harcodeo, va en arch de config.
	int i = 0;

	while (queue_not_empty && max_iterations > i) {
		try {
			Event event = model_events.pop();
			// syslog(LOG_INFO, "[%s:%i]: Pop de un evento del server",
     	// 						 __FILE__, __LINE__);

			handler.handle(event, map);
			i++;
		} catch(ExceptionEmptyQueue& e) {
			queue_not_empty = false;
		}
	}
}

void Game::update() {
	is_running = false;
}


Game::~Game() {}
