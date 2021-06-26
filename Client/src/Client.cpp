#include "Client.h"

Client::Client(const std::string& host, const std::string& port):
			 socket(host, port), model_events(), client_events(),
			 reciever(socket, model_events), sender(socket, client_events) {}

		
		
void Client::execute(int argc, char** argv) {
	Initiator initiator(reciever, sender, model_events, client_events);
	bool game_started;
	initiator.launch(socket, argc, argv, game_started, players);
	if (game_started) {
		Game game(model_events, client_events);
		game.execute();
	}
	reciever.stop_running();
	sender.stop_running();
}


Client::~Client() {

}
