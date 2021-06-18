#ifndef _MATCH_H
#define _MATCH_H

#include <string>
#include <mutex>
#include <map>
#include <atomic>
#include <memory>

#include "Player.h"
#include "Socket.h"
#include "Thread.h"
#include "ProtectedQueue.h"
#include "ModelEvent.h"
#include "Exception.h"
#include "ExceptionMatchStarted.h"
#include "GameWorldTypes.h"
#include "GameWorldFactory.h"
#include "GameWorld.h"


class Match: public Thread {
		std::mutex m;
		std::atomic<bool> match_started;
		std::atomic<bool> finished;
		char last_id;
		std::map<char, Player*> players; //char id_player
		ProtectedQueue<ClientEvent> to_process_events;
		std::unique_ptr<GameWorld> game_world;

	public:
		Match(Socket& socket, GameWorldType type);

		void join_player_if_not_full(Socket& skt);

		bool is_finished();

		virtual void run() override;
		void stop_running();		
		~Match();

	private:
		Match(const Match &other) = delete;
		Match& operator=(const Match &other) = delete;
};


#endif
