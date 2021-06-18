#ifndef _PLAYER_H
#define _PLAYER_H

#include <memory>

#include "Socket.h"
#include "ProtectedQueue.h"
#include "ModelEvent.h"
#include "EventReceiverThread.h"
#include "ModelSenderThread.h"

class Player {
	Socket socket;
	int id;
	EventReceiverThread receiver;
	ProtectedQueue<std::shared_ptr<ModelEvent>> model_events;
	ModelSenderThread sender;

	public:
		Player(Socket& socket, int player_id, ProtectedQueue<ClientEvent>& client_events);
		~Player();
		void push(std::shared_ptr<ModelEvent> model_event);
		void stop_running();

	private:
		Player(const Player &other) = delete;
		Player& operator=(const Player &other) = delete;
};


#endif
