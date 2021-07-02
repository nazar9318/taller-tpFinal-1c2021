#include "StopAttackingHandler.h"

StopAttackingHandler::StopAttackingHandler() {}

void StopAttackingHandler::handle(Event& event, GameWorld& world){
	world.get_character(event.get_id()).stop_attacking();
}

StopAttackingHandler::~StopAttackingHandler(){}
