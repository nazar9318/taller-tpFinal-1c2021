#ifndef _LOBBY_H
#define _LOBBY_H

#include <iostream>
#include <string>
#include "Socket.h"
#include "Thread.h"
#include "Protocol.h"
#include "Matches.h"
#include "ExceptionInvalidCommand.h"
#include "TypesOfEvents.h"
#include "GetMapsHandler.h"
#include "GetMatchesHandler.h"
#include "CreateMatchHandler.h"
#include "JoinMatchHandler.h"
#include "ErrorEvent.h"


class Lobby: public Thread {
		Protocol protocol;
		Socket communication_skt;
		Matches& matches;
		std::atomic<bool> finished;

	public:
		Lobby(Socket& skt, Matches& matches);
		bool is_finished();

		// POST: Finaliza la conexion cliente-servidor. 
		void stop_running();

		// POST: Inicia la comunicacion entre el cliente
		//       y el servidor. Termina cuando ocurre un 
		//       error o el cliente tiene asignada una 
		//       partida.  
		virtual void run() override;
		~Lobby();

	private:
		// Descripcion: implementa la logica del metodo run. 
		void handle_lobby();

		// Descripcion: manda un mensaje al cliente esperando
		//              por un nombre de usuario y lo devuelve.
		std::string get_user_name();

		Lobby(const Lobby &other) = delete;
		Lobby& operator=(const Lobby &other) = delete;
};

#endif
