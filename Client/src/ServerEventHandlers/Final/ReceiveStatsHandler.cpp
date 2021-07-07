#include "ReceiveStatsHandler.h"

ReceiveStatsHandler::ReceiveStatsHandler() {}

void ReceiveStatsHandler::handle(FaseType& fase, Event& event, GameMap& map) {
	fase = FaseType::END_ROUND; 
	std::vector<char> event_msg = event.get_msg();
	for (auto it = event_msg.begin() + 1; it != event_msg.end(); it += 9) {
		char id = *it;
		int kills_round = *((int*)&(*(it + 1)));
		int kills_total = *((int*)&(*(it + 5)));
		map.add_stats(id, kills_round, kills_total);
	}
}

ReceiveStatsHandler::~ReceiveStatsHandler() {}
