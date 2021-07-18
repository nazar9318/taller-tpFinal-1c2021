#include "SendStatsEvent.h"

SendStatsEvent::SendStatsEvent(GameWorld& world, bool finished) {
	this->msg.push_back((char)ModelTypeEvent::STATISTICS);
	this->msg.push_back((char)finished);

	int team_one_wins;
	int team_two_wins;
	int total_rounds = CF::number_rounds;
	world.get_wins(team_one_wins, team_two_wins);
	push_back(total_rounds);
	push_back(team_one_wins);
	push_back(team_two_wins);
	char last_winner = world.get_last_winner();
	msg.push_back(last_winner);
	std::vector<char> stats = world.get_step_info().get_stats();
	std::copy(stats.begin(), stats.end(), std::back_inserter(msg));
}

SendStatsEvent::~SendStatsEvent() {
}
