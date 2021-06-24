#ifndef _MATCH_H
#define _MATCH_H

#include <string>
#include <mutex>
#include <map>
#include <atomic>
#include <memory>
#include <chrono>


#include "Configuration.h"
#include "Player.h"
#include "Socket.h"
#include "Thread.h"
#include "ProtectedQueue.h"
#include "Exception.h"
#include "ExceptionMatchStarted.h"
#include "NotEnoughPlayersException.h"

#include "GameWorld.h"
#include "Event.h"
#include "ErrorEvent.h"
#include "StartGameHandler.h"
#include "SendPlayersInfoEvent.h"
#include "SendPlayersIdsEvent.h"

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
		Match(Socket& socket, const std::string& map_type,
			 std::string player_name);

		void join_player_if_not_full(Socket& skt,
						 std::string player_name);

		bool is_finished();

		virtual void run() override;
		void stop_running();
		~Match();

	private:
		void start_game();
		void game_loop();
		void push_event(std::shared_ptr<Event>& event);
		void handle_events();



		Match(const Match &other) = delete;
		Match& operator=(const Match &other) = delete;
};


#endif
