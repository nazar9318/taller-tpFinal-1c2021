#include "ReceiveStatsHandler.h"

ReceiveStatsHandler::ReceiveStatsHandler() {}

void ReceiveStatsHandler::handle(FaseType& fase, Event& event, GameMap& map) {	
	std::vector<char> event_msg = event.get_msg();
	bool finished = (bool)event_msg[1];
	if (finished) 
		fase = FaseType::ENDGAME;
	else 
		fase = FaseType::END_ROUND; 

	//int wins_one = 1; 
	//int wins_two = 3;

	for (auto it = event_msg.begin() + 2; it != event_msg.end(); it += 9) {
		char id = *it;
		int kills_round = *((int*)&(*(it + 1)));
		int kills_total = *((int*)&(*(it + 5)));
		map.add_stats(id, kills_round, kills_total);
	}


}

ReceiveStatsHandler::~ReceiveStatsHandler() {}
