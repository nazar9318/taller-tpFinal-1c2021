#include "Game.h"

#define FROM_RAD_TO_DEG 57.295779513

Game::Game(ProtectedQueue<Event>& model,
	ProtectedQueue<std::unique_ptr<Event>>& client,
	std::map<char, std::string>& charactersInfo, char& player_id) :
model_events(model), client_events(client), is_running(true),
player(player_id, charactersInfo.at(player_id)),
window("Counter 2d", 800, 600, false), renderer(window), camera(renderer, 800, 600), hud(renderer, 800, 600),
 map(renderer, player,camera, characters, hud), initial_fase(renderer, 800, 600), final_phase(renderer, 800, 600),
prev_mouse_x(0), prev_mouse_y(0), fase(FaseType::INITIAL_FASE) {
	for (auto it = charactersInfo.begin(); it != charactersInfo.end(); ++it) {
		if (it->first != player_id) {
			ClientCharacter character(it->second);
			characters.insert({it->first, std::move(character)});
		}
	}
}

void Game::execute() {
	try {
		using namespace std::chrono;
		auto begin = steady_clock::now();
		auto end = steady_clock::now();
		double t_delta;
		loadMedia();
		/*final_phase.addScore("Federico", 9, 845);
		final_phase.addScore("Mateo", 23, 875);
		final_phase.addScore("Santiago", 832, 865);*/
		while (is_running) {
			begin = steady_clock::now();
			// if(fase == initial){
			// 	initial_fase.run();
			// }
			is_running = handle_events();
			process_events();
			render();
			end = steady_clock::now();
			t_delta = duration<double>(end - begin).count();
			std::this_thread::sleep_for(duration<double>(STEP_TIME - t_delta));
		}
	} catch (std::exception& e) {
		syslog(LOG_CRIT, "[%s:%i]: Exception: %s", __FILE__, __LINE__,  e.what());
	}
}

void Game::loadMedia() {
	map.loadMedia();
	hud.loadMedia();
	initial_fase.loadMedia();
	final_phase.loadMedia();
}

void Game::render() {
	renderer.clearScreen();
	map.renderGround();
	if (fase == FaseType::INITIAL_FASE) {
		//final_phase.render();
		initial_fase.render();
	} else if (fase == FaseType::PLAYING) {
		map.renderWeapons();
		map.renderPlayer();
		map.renderPlayerWeapon();
		map.renderCharacters();
		hud.render();
	} else {
		//final_phase.render();
	}
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

void Game::handle_key_press(SDL_Event& event) {
	switch (event.key.keysym.sym) {
		case SDLK_w: {
			std::unique_ptr<Event> move(new MoveEvent(Direction::UP));
			this->client_events.push(move);
			break;
		}
		case SDLK_a: {
			std::unique_ptr<Event> move(new MoveEvent(Direction::LEFT));
			this->client_events.push(move);
			break;
		}
		case SDLK_d: {
			std::unique_ptr<Event> move(new MoveEvent(Direction::RIGHT));
			this->client_events.push(move);
			break;
		}
		case SDLK_s: {
			std::unique_ptr<Event> move(new MoveEvent(Direction::DOWN));
			this->client_events.push(move);
			break;
		}
		case SDLK_SPACE: {
			std::unique_ptr<Event> grab(new GrabWeaponEvent());
			this->client_events.push(grab);
			break;
		}
		case SDLK_c: {
			std::unique_ptr<Event> change(new ChangeWeaponEvent());
			this->client_events.push(change);
			//player.changeClip();
			break;
		}
		case SDLK_q: {
			std::unique_ptr<Event> plant(new StartPlantBombEvent());
			this->client_events.push(plant);
			break;
		}
		case SDLK_e: {
			std::unique_ptr<Event> deactivate(new StartDeactivateBombEvent());
			this->client_events.push(deactivate);
			break;
		}
	}
}

void Game::handle_key_release(SDL_Event& event) {
	if (event.key.keysym.sym == SDLK_w || event.key.keysym.sym == SDLK_a ||
		event.key.keysym.sym == SDLK_d || event.key.keysym.sym == SDLK_s ) {
			std::unique_ptr<Event> move(new MoveEvent(Direction::STOP_MOVING));
			this->client_events.push(move);
	} else if (event.key.keysym.sym == SDLK_q) {
		std::unique_ptr<Event> plant(new StopPlantBombEvent());
		this->client_events.push(plant);
	} else if (event.key.keysym.sym == SDLK_e) {
		std::unique_ptr<Event> deactivate(new StopDeactivateBombEvent());
		this->client_events.push(deactivate);
	}
}

void Game::handle_click(SDL_Event& event) {
	switch (event.button.button) {
		case SDL_BUTTON_RIGHT: {/*Lo dejamos por si necesitamos este botón*/}
		case SDL_BUTTON_LEFT:{
			std::unique_ptr<Event> shoot(new AttackEvent());
			this->client_events.push(shoot);
			break;
		}
	}
}

void Game::handle_unclick(SDL_Event& event) {
	switch (event.button.button) {
		case SDL_BUTTON_RIGHT:
			break;
		case SDL_BUTTON_LEFT: {
			std::unique_ptr<Event> shoot(new StopAttack());
			this->client_events.push(shoot);
			break;
		}
	}
}

void Game::handle_mouse_motion() {

	SDL_Rect player_pos = player.getBox();

	int delta_x; int delta_y;
	int mouse_x, mouse_y;
	int angle;
	SDL_GetMouseState(&mouse_x, &mouse_y);
	delta_x = mouse_x - (player_pos.x + player_pos.w/2);
	delta_y = (-1) * (mouse_y - (player_pos.y + player_pos.h/2));
	angle = (int)((atan2(delta_y, delta_x) * FROM_RAD_TO_DEG));
	// if (delta_x < 0) {
	// 	angle += 180;
	// }
	angle = (angle+360) % 360;
	std::unique_ptr<Event> move(new ChangeAngleEvent(angle));
	this->client_events.push(move);
}

void Game::process_events() {
	bool queue_not_empty = true;
	int max_iterations = 15;//harcodeo, va en arch de config.
	int i = 0;
	while (queue_not_empty && max_iterations > i) {
		try {
			Event event = model_events.pop();
			handler.handle(fase, event, map);
			i++;
		} catch(ExceptionEmptyQueue& e) {
			queue_not_empty = false;
		}
	}
}

void Game::update() { is_running = false; }

Game::~Game() {}
