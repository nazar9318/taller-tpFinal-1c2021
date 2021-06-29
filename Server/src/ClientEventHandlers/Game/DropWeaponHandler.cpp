#include "DropWeaponHandler.h"

DropWeaponHandler::DropWeaponHandler() {}

void DropWeaponHandler::handle(Event& event, GameWorld& world){
	/*
	Character& character = world.get_character(event.get_id())
	std::unique_ptr<Weapon> weapon = character.drop_optative_weapon();
	world.add_weapon(character.get_pos(), weapon);
	*/
}

DropWeaponHandler::~DropWeaponHandler(){}
