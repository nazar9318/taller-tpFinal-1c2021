#include "GrabWeaponHandler.h"

GrabWeaponHandler::GrabWeaponHandler() {}

void GrabWeaponHandler::handle(Event& event, GameWorld& world){
	/*
	Character& character = world.get_character(event.get_id());
	std::unique_ptr<Weapon> weapon =
					 world.find_closest_weapon(character.get_pos());
	if (character.has_optative_weapon()) {
		std::unique_ptr<Weapon> weapon = character.drop_optative_weapon();
		world.add_weapon(character.get_pos(), weapon);
	}
	character.add_weapon(std::move(weapon)); 
	*/
}

GrabWeaponHandler::~GrabWeaponHandler(){}
