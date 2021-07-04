#include "Team.h"

Team get_opposite(Team team) {
	if (team == Team::TERRORIST)
		return Team::COUNTER_ENEMY;
	return Team::TERRORIST;
}
