#ifndef _TYPES_OF_EVENTS_H_
#define _TYPES_OF_EVENTS_H_


#define STEP_TIME 0.0333

enum ClientTypeEvent: char {
	MOVE, //type/direction
	ROTATE, //angle
	START_ATTACKING, //type/angle
	STOP_ATTACKING, //type
	GRAB_WEAPON, //type
	DROP_WEAPON, //type
	CHANGE_WEAPON,//type
	START_PLANTING_BOMB, //type
	STOP_PLANTING_BOMB, //type
	START_DEACTIVATING_BOMB,//Type
	STOP_DEACTIVATING_BOMB,//Type
	BUY_WEAPON,//type, weapon
	BUY_BULLETS,//type, weapon, cantidad
	START_GAME, // Loby. Manda el cliente creador.
	QUIT_GAME,
	GET_MAPS, // Loby
	GET_MATCHES, // Loby
	CREATE, // Loby
	JOIN, // Loby
	USER_NAME, // Loby
	CREATOR_ABANDONS
};

enum ModelTypeEvent: char {
	SEND_MAPS, // Loby
	SEND_MATCHES, // Loby
	SUCCESSFUL_ENTRY, // Loby
	PLAYERS_ID_LIST, // Loby
	SEND_FULL_MAP, // EventType, width,height, x,y, type, ...
	SEND_WEAPONS,
	GAME_STARTED, // primer mensaje a todos, luego full map.
	GAME_FINISHED, //manda los resultados. FALTA USAR.
	BOMB_INFO, // protocolo en Bomb.cpp. 
	ERROR,
	PLAYING_STEP,
	ATTACKS_INFO, 
	BUYS,
	INITIAL_PLAYERS,
	STATISTICS,
	FINAL_STATE,
	INIT_STEP,
	FINAL_STEP,
	SEND_SQUADS,

	STEP_INFO // id,posicion,plata,vida,arma;id,posicion,plata,vida,arma


};

enum ServerError: char {
	MATCH_FULL,
	NOT_ENOUGH_PLAYERS,
	MATCH_ALREADY_STARTED,
	INVALID_TYPE_EVENT,
	MATCH_NOT_FOUND,
	MATCH_ALREADY_EXISTS, 
	CREATOR_ABANDONS_MATCH
};


enum Direction: char {
	RIGHT,
	LEFT,
	UP,
	DOWN,
	STOP_MOVING
};

enum SoundEvent: char {
	AK47_SOUND,
	M3_SOUND,
	GLOCK_SOUND,
	AWP_SOUND,
	KNIFE_SOUND,
	BOMB_PLACED_SOUND,
	BOMB_DEACTIVATED_SOUND,
	BOMB_EXPLODED_SOUND
};

enum PositionType: char {
	AZTEC,
	INFERNO,
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
	AWP,
	NO_WEAPON
};

// CONSTANTS FOR EVENTS

#define START_CREATE_NAME 1
#define START_JOIN_NAME 1

#endif
