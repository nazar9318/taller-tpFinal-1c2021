#ifndef _TYPES_OF_EVENTS_H_
#define _TYPES_OF_EVENTS_H_


enum ClientTypeEvent: char {
	MOVE, //type/direction
	START_ATTACKING, //type/angle
	GRAB_WEAPON, //type
	DROP_WEAPON, //type
	CHANGE_WEAPON,//type
	PLANT_BOMB, //type
	DEACTIVATE_BOMB,//Type
	BUY_WEAPON,//type, weapon
	BUY_BULLETS,//type, weapon, cantidad
	START_GAME,
	QUIT_GAME,
	GET_MAPS,
	GET_MATCHES,
	CREATE,
	JOIN,
	USER_NAME
};

enum ModelTypeEvent: char {
	SEND_MAPS,//Loby
	SEND_MATCHES,//Loby
	SUCCESSFUL_ENTRY,//Loby
	PLAYERS_ID_LIST,//Loby
	SEND_FULL_MAP,//EventType, width,height,
	GAME_STARTED,
	STEP_INFO,// id,posicion,plata,vida,arma;id,posicion,plata,vida,arma
	GAME_FINISHED, //manda los resultados
	ERROR
};

enum ServerError: char {
	INVALID_COMMAND,
	MATCH_FULL,
	NOT_ENOUGH_PLAYERS
};


enum Direction: char {
	RIGHT,
	LEFT,
	UP,
	DOWN,
	STOP_MOVING
};

enum PositionType: char {
	AZTEC,
	INFIERNO,
	DUST,
	BOMB_AREA_A,
	BOMB_AREA_B,
	BOMB_AREA_C,
	BOX_BLACK,
	BOX_BROWN,
	BOX_METAL,
	BOX_WOOD_METAL,
	BOX_WOOD,
	TERRORIST_SPAWN,
	COUNTER_SPAWN,
	BOMB,
	KNIFE,
	GLOCK,
	AK47,
	M3,
	AWP
};


// CONSTANTS FOR EVENTS


#define START_CREATE_NAME 1
#define START_JOIN_NAME 1








#endif
