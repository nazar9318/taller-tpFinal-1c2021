#include "Game.h"

Game::Game(ProtectedQueue<Event>& model,
		 ProtectedQueue<std::unique_ptr<Event>>& client, std::map<char, std::string>& charactersInfo,
		 char& player_id):
		  model_events(model), client_events(client),
		  is_running(true), player(player_id, charactersInfo.at(player_id)),
			window("Counter 2d", 800, 600, false), renderer(window), map(renderer){

			for (auto it = charactersInfo.begin(); it != charactersInfo.end(); ++it) {
				if(it->first != player_id){
					ClientCharacter character(it->second);
					characters.insert({it->first, std::move(character)});
				}
			}

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

void Game::loadMedia() { map.loadMedia(); }

void Game::render(){
	renderer.clearScreen();
	map.renderGround();
	map.renderWeapons();
	// renderer.setDrawColor(0xFF,0xFF,0xFF,0xFF);
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
		case SDLK_w: {
			std::unique_ptr<Event> move(new MoveEvent(Direction::UP));
			this->client_events.push(move);
			break;
		}
		case SDLK_a:{
			std::unique_ptr<Event> move(new MoveEvent(Direction::LEFT));
			this->client_events.push(move);
			break;
		}
		case SDLK_d:{
			std::unique_ptr<Event> move(new MoveEvent(Direction::RIGHT));
			this->client_events.push(move);
			break;
		}
		case SDLK_s:{
			std::unique_ptr<Event> move(new MoveEvent(Direction::DOWN));
			this->client_events.push(move);
			break;
		}
		case SDLK_SPACE:{
			std::unique_ptr<Event> grab(new GrabWeaponEvent());
			this->client_events.push(grab);
			break;
		}
	}
}

void Game::handle_key_release(SDL_Event& event) {
	if (event.key.keysym.sym == SDLK_w || event.key.keysym.sym == SDLK_a ||
		event.key.keysym.sym == SDLK_d || event.key.keysym.sym == SDLK_s ) {
			std::unique_ptr<Event> move(new MoveEvent(Direction::STOP_MOVING));
			this->client_events.push(move);
		}
	/*switch (event.key.keysym.sym) {
		case SDLK_w: {
			std::unique_ptr<Event> move(new MoveEvent(Direction::STOP_MOVING));
			this->client_events.push(move);
			break;
		}
		case SDLK_a: {
			std::unique_ptr<Event> move(new MoveEvent(Direction::STOP_MOVING));
			this->client_events.push(move);
			break;
		}
		case SDLK_d:{
			std::unique_ptr<Event> move(new MoveEvent(Direction::STOP_MOVING));
			this->client_events.push(move);
			break;
		}
		case SDLK_s: {
			std::unique_ptr<Event> move(new MoveEvent(Direction::STOP_MOVING));
			this->client_events.push(move);
			break;
		}
		case SDLK_SPACE:
		break;
	}*/
}

void Game::handle_click(SDL_Event& event) {
	switch (event.button.button) {
		case SDL_BUTTON_RIGHT: {/*Lo dejamos por si necesitamos este botón*/}
		case SDL_BUTTON_LEFT:{
			std::unique_ptr<Event> shoot(new AttackEvent());
			break;
		}
			// std::unique_ptr<Event> event(new MoveEvent());
			// client_events.push(event);
	}
}

void Game::handle_unclick(SDL_Event& event) {
	switch (event.button.button) {
		case SDL_BUTTON_RIGHT:
			break;
		case SDL_BUTTON_LEFT:{
			std::unique_ptr<Event> shoot(new StopAttack());
			break;
		}
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
