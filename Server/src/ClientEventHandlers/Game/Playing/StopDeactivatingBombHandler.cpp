#include "StopDeactivatingBombHandler.h"

StopDeactivatingBombHandler::StopDeactivatingBombHandler() {}

void StopDeactivatingBombHandler::handle(Event& event, GameWorld& world){
	Character& character = world.get_character(event.get_id());
	world.stop_deactivating_bomb(event.get_id());
	character.unblock();
}

StopDeactivatingBombHandler::~StopDeactivatingBombHandler(){}
