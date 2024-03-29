#include "Game.h"

#define FROM_RAD_TO_DEG 57.295779513

Game::Game(ProtectedQueue<Event>& model,
	ProtectedQueue<std::unique_ptr<Event>>& client,
	std::map<char, std::string>& charactersInfo, char& player_id) :
	model_events(model),
 	client_events(client),
 	is_running(true),
	window("Counter 2d", CCF::widowed_x, CCF::widowed_y, CCF::is_fullscreen),
 	renderer(window),
	player(player_id, charactersInfo.at(player_id), CCF::widowed_x, CCF::widowed_y),
 	camera(renderer, CCF::widowed_x, CCF::widowed_y),
 	hud(renderer, CCF::widowed_x, CCF::widowed_y),
 	final_phase(renderer, CCF::widowed_x, CCF::widowed_y),
 	map(renderer, player,camera, characters, hud, final_phase),
	initial_phase(renderer, CCF::widowed_x, CCF::widowed_y, client, player_id),
 	fase(FaseType::INITIAL_FASE),
	not_finished(true),
	bomb(renderer, camera, player_id, player),
	attack_effects(renderer, camera, player_id, player, characters) {
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
		while (is_running && not_finished) {
			begin = steady_clock::now();
			if (fase == FaseType::INITIAL_FASE) {
				is_running = initial_phase.run();
			} else {
				not_finished = handle_events();
			}
			process_events();
			render();
			end = steady_clock::now();
			t_delta = duration<double>(end - begin).count();
			if (t_delta < STEP_TIME)
				std::this_thread::sleep_for(duration<double>(STEP_TIME - t_delta));
		}

		while (not_finished) {
			begin = steady_clock::now();
			not_finished = handle_finished_game();
			render();
			end = steady_clock::now();
			t_delta = duration<double>(end - begin).count();
			if (t_delta < STEP_TIME)
				std::this_thread::sleep_for(duration<double>(STEP_TIME - t_delta));
		}

	} catch (std::exception& e) {
		syslog(LOG_CRIT, "[%s:%i]: Exception: %s", __FILE__, __LINE__,  e.what());
	}
}

void Game::loadMedia() {
	cursor.setCrusor(SPRITE_POINTER_PATH, 0xFF, 0x00, 0xFF);
	map.loadMedia();
	hud.loadMedia();
	bomb.loadMedia();
	attack_effects.loadMedia();
	initial_phase.loadMedia();
	final_phase.loadMedia();
}

void Game::render() {
	renderer.clearScreen();
	map.renderGround();
	if (fase == FaseType::INITIAL_FASE) {
		initial_phase.render();
	} else if (fase == FaseType::PLAYING) {
		map.renderWeapons();
		attack_effects.render();
		bomb.render();
		map.renderPlayer();
		map.renderCharacters();
		hud.render();
	} else if (fase == FaseType::END_ROUND) {
		final_phase.render();
	} else if (fase == FaseType::ENDGAME) {
		final_phase.endGame();
		final_phase.render();
		is_running = false;
	}
	renderer.presentScreen();
}

bool Game::handle_finished_game(){
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if(event.type == SDL_QUIT){
			return false;
		}
		if(event.type == SDL_KEYDOWN){
			if(event.key.keysym.sym == SDLK_ESCAPE){
				window.changeFullScreen();
			}
		}
	}
	return true;
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
	if (event.key.repeat == 0) {
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
			case SDLK_ESCAPE: {
				window.changeFullScreen();
				break;
			}
		}
	}
}

void Game::handle_key_release(SDL_Event& event) {
	switch (event.key.keysym.sym) {
		case SDLK_w: {
			std::unique_ptr<Event> move(
						new MoveEvent(Direction::STOP_MOVING_UP));
			this->client_events.push(move);
			break;
		}
		case SDLK_s: {
			std::unique_ptr<Event> move(
						new MoveEvent(Direction::STOP_MOVING_DOWN));
			this->client_events.push(move);
			break;
		}
		case SDLK_a: {
			std::unique_ptr<Event> move(
						new MoveEvent(Direction::STOP_MOVING_LEFT));
			this->client_events.push(move);
			break;
		}
		case SDLK_d: {
			std::unique_ptr<Event> move(
						new MoveEvent(Direction::STOP_MOVING_RIGHT));
			this->client_events.push(move);
			break;
		}
		case SDLK_q: {
			std::unique_ptr<Event> plant(new StopPlantBombEvent());
			this->client_events.push(plant);
			break;
		}
		case SDLK_e: {
			std::unique_ptr<Event> deactivate(new StopDeactivateBombEvent());
			this->client_events.push(deactivate);
			break;
		}
	}
}

void Game::handle_click(SDL_Event& event) {
	switch (event.button.button) {
		case SDL_BUTTON_LEFT:{
			std::unique_ptr<Event> shoot(new AttackEvent());
			this->client_events.push(shoot);
			break;
		}
		default : break;
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
	SDL_Point camera_pos = camera.getPos();

	int delta_x; int delta_y;
	int mouse_x, mouse_y;
	int angle;
	SDL_GetMouseState(&mouse_x, &mouse_y);

	mouse_x += camera_pos.x;
	mouse_y += camera_pos.y;

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
			handler.handle(fase, event, map, bomb, attack_effects, initial_phase);
			i++;
		} catch(ExceptionEmptyQueue& e) {
			queue_not_empty = false;
		}
	}
}


void Game::update() { is_running = false; }

Game::~Game() {}
