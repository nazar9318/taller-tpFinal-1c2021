#include "Client.h"

Client::Client(const std::string& host, const std::string& port):
			 socket(host, port), model_events(), client_events(),
			 reciever(socket, model_events), sender(socket, client_events) {
	reciever.start();
	sender.start();
}
		
		
void Client::execute() {
	GameMap map;
	Lobby lobby(model_events, client_events, map);
	bool game_started = lobby.launch();
	if (game_started) {
		Game game(model_events, client_events, map);
		game.execute();
	}
	reciever.stop_running();
	sender.stop_running();
}


/*
void Client::execute_game() { 
	
	FrameLimiter frame_limiter;
	while (is_running) {
		handle_events();
		process_events();
		update();
		render();
		frame_limiter.sleep();
	}

}

*/


Client::~Client() {}
