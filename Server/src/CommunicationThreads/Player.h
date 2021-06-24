#ifndef _PLAYER_H
#define _PLAYER_H

#include <memory>
#include <string>

#include "Socket.h"
#include "ProtectedQueue.h"
#include "EventReceiverThread.h"
#include "ModelSenderThread.h"
#include "Event.h"
#include "EntrySuccessfulEvent.h"

class Player {
	Socket socket;
	int id;
	std::string name;
	EventReceiverThread receiver;
	ProtectedQueue<std::shared_ptr<Event>> model_events;
	ModelSenderThread sender;

	public:
		Player(Socket& socket, int player_id, std::string name,
					  ProtectedQueue<Event>& client_events);
		~Player();
		void push(std::shared_ptr<Event> model_event);
		void stop_running();
		std::string get_name() const;

	private:
		Player(const Player &other) = delete;
		Player& operator=(const Player &other) = delete;
};


#endif
