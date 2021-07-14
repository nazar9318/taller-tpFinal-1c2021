#include "DeactivateBombHandler.h"

DeactivateBombHandler::DeactivateBombHandler() {}

void DeactivateBombHandler::handle(Event& event, GameWorld& world){
	Character& character = world.get_character(event.get_id());
	b2Vec2 pos = character.get_pos();
	if ((character.is_alive()) && 
			(world.deactivate_bomb(character.get_team(), event.get_id(), pos))) {
		character.block();
	}
}

DeactivateBombHandler::~DeactivateBombHandler(){}
