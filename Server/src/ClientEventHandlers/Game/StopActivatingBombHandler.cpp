#include "StopActivatingBombHandler.h"

StopActivatingBombHandler::StopActivatingBombHandler() {}

void StopActivatingBombHandler::handle(Event& event, GameWorld& world){
	Character& character = world.get_character(event.get_id());
	world.stop_activating_bomb(event.get_id());
	character.unblock();
}

StopActivatingBombHandler::~StopActivatingBombHandler(){}
