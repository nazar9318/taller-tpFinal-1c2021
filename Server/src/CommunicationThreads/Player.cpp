#include "Player.h"
#include <syslog.h>

// POST: Crea un jugador con el id correspondiente. Lanza dos
//       hilos, uno en el que escucha mensajes a traves del 
//       protocolo y otro en el que envia mensajes. 
Player::Player(Socket& skt, char player_id, const std::string& player_name,
			ProtectedQueue<Event>& client_events, bool is_creator):
			socket(std::move(skt)), id(player_id),
			name(player_name), receiver(socket, id, client_events, is_creator),
			model_events(), sender(socket, model_events)  {
	EntrySuccessfulEvent event(id);
	Protocol protocol;
	syslog(LOG_INFO, "[%s:%i]: Por enviar mensaje de entry successful",
					 __FILE__, __LINE__);
	protocol.send_event(socket, event.get_msg());
	sender.start();
	receiver.start();
}

// POST: Encola el evento en la cola de eventos a enviar por el 
//       protocolo.
void Player::push(std::shared_ptr<Event>& model_event) {
	model_events.push(model_event);
}

std::string Player::get_name() const{
	return name;
}

// POST: Fuerza la finalizacion del jugador.
void Player::stop_running() {
	syslog(LOG_INFO, "[%s:%i]: Por eliminar a sender y receiver",
				 __FILE__, __LINE__);
	sender.stop_running();
	receiver.stop_running();
}

Player::~Player() {
	syslog(LOG_INFO, "[%s:%i]: Se elimina el player",
				__FILE__, __LINE__);
}
