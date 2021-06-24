#ifndef _TYPES_OF_EVENTS_H_
#define _TYPES_OF_EVENTS_H_


enum ClientTypeEvent: char {
	MOVE,
	START_ATTACKING, 
	GRAB_WEAPON, 
	DROP_WEAPON, 
	EXCHANGE_WEAPON,
	BUY_ARMOUR, 
	START_GAME, 
	QUIT_GAME, 
	GET_MAPS, 
	GET_MATCHES, 
	CREATE, 
	JOIN, 
	USER_NAME
};

enum ModelTypeEvent: char {
	SEND_MAPS, 
	SEND_MATCHES,
	SEND_FULL_MAP,
	GAME_STARTED, 
	PLAYERS_INFO,
	SUCCESSFUL_ENTRY,
	// id,posicion,plata,vida,arma;id,posicion,plata,vida,arma
	SEND_ATTACK, 
	BOMB_STATE, //activada/descativada;tiempo; 
	ROUND_FINISHED, 
	GAME_FINISHED, //manda los resultados 
	PLAYERS_ID_LIST,
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
