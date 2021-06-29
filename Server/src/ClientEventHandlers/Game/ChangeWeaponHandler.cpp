#include "ChangeWeaponHandler.h"

ChangeWeaponHandler::ChangeWeaponHandler() {}

void ChangeWeaponHandler::handle(Event& event, GameWorld& world){
	
	world.get_character(event.get_id())
	     .change_weapon();

}

ChangeWeaponHandler::~ChangeWeaponHandler(){}
