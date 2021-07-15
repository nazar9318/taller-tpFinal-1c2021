#include "ReceiveStatsHandler.h"

ReceiveStatsHandler::ReceiveStatsHandler() {}
#include <iostream>
void ReceiveStatsHandler::handle(FaseType& fase, Event& event, GameMap& map) {	
	std::vector<char> event_msg = event.get_msg();
	bool finished = (bool)event_msg[1];
	if (finished) { fase = FaseType::ENDGAME; }
	else { fase = FaseType::END_ROUND; }
	auto it = event_msg.begin();
	int wins_one = *((int*)&(*(it + 2))); 
	int wins_two = *((int*)&(*(it + 6)));
	it += 10;
	std::cout << "wins_one " << wins_one << " wins_two " <<wins_two << std::endl;
	for (; it != event_msg.end(); it += 9) {
		char id = *it;
		int kills_round = *((int*)&(*(it + 1)));
		int kills_total = *((int*)&(*(it + 5)));
		map.add_stats(id, kills_round, kills_total);
		//el nuevo método tendría que ser:
		//map.add_stats(id, muertes_totales, dinero_ganado_en_la_ronda,kills_round, kills_total);
	}
}

ReceiveStatsHandler::~ReceiveStatsHandler() {}
