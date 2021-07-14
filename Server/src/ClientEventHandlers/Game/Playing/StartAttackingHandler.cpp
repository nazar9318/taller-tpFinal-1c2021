#include "StartAttackingHandler.h"

StartAttackingHandler::StartAttackingHandler() {}

void StartAttackingHandler::handle(Event& event, GameWorld& world){
	world.get_character(event.get_id())
		 .start_attacking();
}

StartAttackingHandler::~StartAttackingHandler(){}
