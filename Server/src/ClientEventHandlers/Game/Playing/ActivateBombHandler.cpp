#include "ActivateBombHandler.h"

ActivateBombHandler::ActivateBombHandler() {}

void ActivateBombHandler::handle(Event& event, GameWorld& world){
	Character& character = world.get_character(event.get_id());
	b2Vec2 pos = character.get_pos();
	if ((character.is_alive()) && 
		(world.activate_bomb(event.get_id(), pos))) {
		character.block();
	}
}

ActivateBombHandler::~ActivateBombHandler(){}
