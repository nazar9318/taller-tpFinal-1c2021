#include "Client.h"

Client::Client() {
}

void Client::execute(int argc, char** argv) {
	bool client_active = true;
	bool user_name_charged = false;
	std::string name;
	std::string port;
	std::string host;
	while (client_active) {
		Socket socket;
		ProtectedQueue<Event> model_events;
		ProtectedQueue<std::unique_ptr<Event>> client_events;
		ModelRecieverThread reciever(socket, model_events);
		EventSenderThread sender(socket, client_events);
		std::map<char, std::string> players;
		Initiator initiator(reciever, sender,
					model_events, client_events, client_active, port, host);
		bool game_started = false;
		char self_id;
		initiator.launch(socket, argc, argv, game_started,
							players, self_id, user_name_charged, name);
		if (game_started) {
			Game game(model_events, client_events, players, self_id);
			game.execute();
		}
		reciever.stop_running();
		sender.stop_running();
	}
}

Client::~Client() {}
