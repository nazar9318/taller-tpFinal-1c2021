#ifndef TEAM_H
#define TEAM_H

enum Team: char {
	TERRORIST = 50,
	COUNTER_ENEMY
};

Team get_opposite(Team team);

#endif
