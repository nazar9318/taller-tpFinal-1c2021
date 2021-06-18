#include "Player.h"



Player::Player(Socket& skt, int player_id,
			ProtectedQueue<ClientEvent>& client_events):
			socket(std::move(skt)), id(player_id), 
			receiver(socket, id, client_events), model_events(),
			sender(socket, model_events)  {
	sender.start();
	receiver.start();
}


void Player::push(std::shared_ptr<ModelEvent> model_event) {
	model_events.push(model_event);
}


void Player::stop_running() {
	sender.stop_running();
	receiver.stop_running();
}

Player::~Player() {}
