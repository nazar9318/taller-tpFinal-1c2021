#ifndef TEAM_H
#define TEAM_H

enum Team: char {
	TERRORIST = 50,
	COUNTER_ENEMY
};

enum Equipped_Weapon: char {
	KNIFE_EQUIPPED = 70,
	GLOCK_EQUIPPED,
	M3_EQUIPPED,
	AWP_EQUIPPED,
	AK47_EQUIPPED
};

Team get_opposite(Team team);

#endif
