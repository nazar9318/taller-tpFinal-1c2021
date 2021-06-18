#include "Client.h"

Client::Client(const std::string& host, const std::string& port):
			 socket(host, port), model_events(), client_events(),
			 reciever(socket, model_events), sender(socket, client_events) {}

		
		
void Client::execute() {
	GameMap map;
	Initiator initiator(map);
	bool game_started = initiator.launch(socket);
	if (game_started) {
		reciever.start();
		sender.start();
		Game game(model_events, client_events, map);
		game.execute();
		reciever.stop_running();
		sender.stop_running();
	}
}


Client::~Client() {

}
