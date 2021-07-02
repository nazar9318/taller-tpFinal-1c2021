#include "MoveHandler.h"
#include <syslog.h>

MoveHandler::MoveHandler() {}

void MoveHandler::handle(Event& event, GameWorld& world){
	syslog(LOG_INFO, "[%s:%i]: Mensaje de mover recibido: %d",
	 __FILE__, __LINE__, (int)(event.get_msg()[1]));

	// msg[1] es la direccion.  
	world.get_character(event.get_id())
		.set_move_state((Direction)(event.get_msg()[1]));
}

MoveHandler::~MoveHandler(){}
