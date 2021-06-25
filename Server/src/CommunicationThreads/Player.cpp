#include "Player.h"
#include <syslog.h>


Player::Player(Socket& skt, int player_id, std::string player_name,
			ProtectedQueue<Event>& client_events):
			socket(std::move(skt)), id(player_id),
			name(player_name),receiver(socket, id, client_events),
			model_events(), sender(socket, model_events)  {
	EntrySuccessfulEvent event(id);
	Protocol protocol;
	syslog(LOG_INFO, "[%s:%i]: Por enviar mensaje de entry successful",
					 __FILE__, __LINE__);

	protocol.send_event(socket, event.get_msg());
	sender.start();
	receiver.start();
}

void Player::push(std::shared_ptr<Event> model_event) {
	model_events.push(model_event);
}

std::string Player::get_name() const{
	return name;
}


void Player::stop_running() {
	sender.stop_running();
	receiver.stop_running();
}

Player::~Player() {}
