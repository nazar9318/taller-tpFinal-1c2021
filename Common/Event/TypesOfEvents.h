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

enum WeaponType: char {
	BOMB,
	KNIFE,
	GLOCK,
	AK47,
	M3,
	AWP
};

enum ModelTypeEvent: char {
	SEND_MAPS,//Loby
	SEND_MATCHES,//Loby
	SUCCESSFUL_ENTRY,//Loby
	PLAYERS_ID_LIST,//Loby
	SEND_FULL_MAP,//EventType, width,height,
	GAME_STARTED,
	PLAYERS_INFO,
	// id,posicion,plata,vida,arma;id,posicion,plata,vida,arma
	SEND_ATTACK,
	BOMB_STATE, //activada/descativada;tiempo;
	ROUND_FINISHED,
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



// CONSTANTS FOR EVENTS


#define START_CREATE_NAME 1
#define START_JOIN_NAME 1








#endif
