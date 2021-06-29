#include "BuyWeaponHandler.h"

BuyWeaponHandler::BuyWeaponHandler() {}

void BuyWeaponHandler::handle(Event& event, GameWorld& world){
	/*
	Character& character = world.get_character(event.get_id());
	std::unique_ptr<Weapon> weapon_buy(WeaponFactory::create(event[1]));
	if (character.has_enough_to_buy(weapon_buy)) {
		if (character.has_optative_weapon()) {
			std::unique_ptr<Weapon> weapon = character.drop_optative_weapon();
			world.add_weapon(character.get_pos(), weapon);
		}
		character.buy_weapon(std::move(weapon_buy)); 
	}
	*/
}

BuyWeaponHandler::~BuyWeaponHandler(){}
