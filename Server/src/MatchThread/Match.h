#ifndef _MATCH_H
#define _MATCH_H

#include <string>
#include <mutex>
#include <map>
#include <atomic>
#include <memory>
#include <chrono>
#include <syslog.h>

#include "Configuration.h"
#include "Player.h"
#include "Socket.h"
#include "Thread.h"
#include "ProtectedQueue.h"
#include "Exception.h"
#include "ExceptionInvalidCommand.h"
#include "TypesOfEvents.h"

#include "GameWorld.h"
#include "Event.h"
#include "ErrorEvent.h"
#include "StartGameHandler.h"
#include "SendPlayersIdsEvent.h"
#include "StepInformation.h"
#include "SendStepInfoEvent.h"

#include "ClientEventHandler.h"


class Match: public Thread {
		std::mutex m;
		std::atomic<bool> match_started;
		std::atomic<bool> finished;
		char last_id;
		std::map<char, Player*> players; //char id_player
		ProtectedQueue<Event> to_process_events;
		GameWorld game_world;
		ClientEventHandler handler;

	public:
		// POST: Crea una partida con el tipo de mapa correspondiente
		//       y agrega al jugador a la misma. 
		Match(Socket& socket, const std::string& map_type,
			 const std::string& player_name);

		// PRE: La partida no comenzo y tiene lugar para un jugador mas.
		// POST: Une a la partida al jugador. 
		void join_player_if_not_full(Socket& skt,
					const std::string& player_name);

		bool is_finished();

		// Descripcion: Comienza la partida una vez que se lee el mensaje 
		//              correspondiente mediante el protocolo. Implementa 
		//              el game-loop.  
		virtual void run() override;

		// POST: Fuerza la finalizacion de la partida.  
		void stop_running();

		~Match();

	private:

		void start_game();
		void game_loop();

		// POST: Envia el evento a todos los jugadores de la partida.
		void push_event(std::shared_ptr<Event>& event);
		
		// POST: Desencola los eventos recibidos por los clientes y los
		//       maneja. 
		void handle_events();

		Match(const Match &other) = delete;
		Match& operator=(const Match &other) = delete;
};


#endif
