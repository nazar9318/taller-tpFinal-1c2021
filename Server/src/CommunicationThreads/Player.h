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
	char id;
	std::string name;
	EventReceiverThread receiver;
	ProtectedQueue<std::shared_ptr<Event>> model_events;
	ModelSenderThread sender;

	public:
		// POST: Crea un jugador con el id correspondiente. Lanza dos
		//       hilos, uno en el que escucha mensajes a traves del 
		//       protocolo y otro en el que envia mensajes. 
		Player(Socket& socket, char player_id, const std::string& name,
					  ProtectedQueue<Event>& client_events);
		
		// POST: Encola el evento en la cola de eventos a enviar por el 
		//       protocolo. 
		void push(std::shared_ptr<Event>& model_event);

		// POST: Fuerza la finalizacion del jugador. 
		void stop_running();

		std::string get_name() const;
		
		~Player();

	private:
		Player(const Player &other) = delete;
		Player& operator=(const Player &other) = delete;
};


#endif
