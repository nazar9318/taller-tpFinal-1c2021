#include "ReceiveStatsHandler.h"
#include <iostream>

ReceiveStatsHandler::ReceiveStatsHandler() {}

void ReceiveStatsHandler::handle(FaseType& fase, Event& event, GameMap& map) {	
	std::vector<char> event_msg = event.get_msg();
	bool finished = (bool)event_msg[1];
	if (finished) { fase = FaseType::ENDGAME; }
	else { fase = FaseType::END_ROUND; }
	auto it = event_msg.begin();
	int wins_one = *((int*)&(*(it + 2))); 
	int wins_two = *((int*)&(*(it + 6)));
	int last_round_winner = (int)*(it + 10);
	map.setRoundInFinalPhase(wins_one + wins_two);
	map.setWinsToFinalPhase(wins_one, wins_two);
	it += 11;
	for (; it != event_msg.end(); it += 17) {
		char id = *it;
		int kills_round = *((int*)&(*(it + 1)));
		int kills_total = *((int*)&(*(it + 5)));
		int money = *((int*)&(*(it + 9)));
		int times_killed = *((int*)&(*(it + 13)));
		map.add_stats(id, kills_round, kills_total, times_killed,
						money, last_round_winner);
	}
}

ReceiveStatsHandler::~ReceiveStatsHandler() {}
