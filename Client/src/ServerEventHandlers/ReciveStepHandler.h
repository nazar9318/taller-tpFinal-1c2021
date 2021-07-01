#ifndef RECIVE_STEP_HANDLER_H
#define RECIVE_STEP_HANDLER_H

#include <vector>
#include "Event.h"
#include "FaseType.h"
#include "GameMap.h"
#include "Team.h"

class ReciveStepHandler {
	public:
		ReciveStepHandler();

		void handle(Event& event, GameMap& map);

		~ReciveStepHandler();

  private:
		void handle_initial_fase(std::vector<char>& event_msg, GameMap& map);
		void handle_playing_fase(std::vector<char>& event_msg, GameMap& map);
		void handle_end_round_fase(std::vector<char>& event_msg, GameMap& map);


};


#endif
