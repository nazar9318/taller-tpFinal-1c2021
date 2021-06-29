#include "MoveHandler.h"

MoveHandler::MoveHandler() {}

void MoveHandler::handle(Event& event, GameWorld& world){
	// msg[1] es la direccion.  
	world.get_character(event.get_id())
		.set_move_state((Direction)(event.get_msg()[1]));
}

MoveHandler::~MoveHandler(){}
