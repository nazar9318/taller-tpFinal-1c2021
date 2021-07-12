#ifndef _MATCH_H
#define _MATCH_H

/*

**************************************************************

******************FALTA SOLUCIONAR BUG************************

Cuando en la inicializacion el creador sale de la partida, 
no le llega un mensaje al cliente que se unio alertandole que no
va a poder jugar porque el creador no puede arrancar la partida. 
Ademas, el server se rompe. 

*/



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

#include "FaseType.h"
#include "SendStepInitEvent.h"
#include "SendBuysEvent.h"
#include "SendInitPlayersEvent.h"
#include "SendStepPlayingEvent.h"
#include "SendAttacksInfoEvent.h"
#include "SendBombStateEvent.h"
#include "SendFinalStateEvent.h"
#include "SendStatsEvent.h"
#include "SendFinalStepEvent.h"
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
		bool statistics_not_sent; 
		bool init_players_not_sent;
		bool final_state_not_send;

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
		
		// POST: Envia todos los eventos que sucedieron en el ultimo step
		//       dependiendo de la fase actual. 
		void push_step_events();

		// POST: Envia el evento a todos los jugadores de la partida.
		void push_event(std::shared_ptr<Event>& event);
		
		// POST: Desencola los eventos recibidos por los clientes y los
		//       maneja. 
		void handle_events();

		Match(const Match &other) = delete;
		Match& operator=(const Match &other) = delete;
};


#endif
