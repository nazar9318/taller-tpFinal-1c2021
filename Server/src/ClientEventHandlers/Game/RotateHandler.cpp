#include "RotateHandler.h"

RotateHandler::RotateHandler() {}

void RotateHandler::handle(Event& event, GameWorld& world){
	int angle = (int)*((uint16_t*)&(event.get_msg()[1]));
	world.get_character(event.get_id())
		 .set_angle(angle);
}

RotateHandler::~RotateHandler(){}
