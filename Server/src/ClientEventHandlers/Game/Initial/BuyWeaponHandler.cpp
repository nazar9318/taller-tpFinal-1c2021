#include "BuyWeaponHandler.h"

BuyWeaponHandler::BuyWeaponHandler() {}

void BuyWeaponHandler::handle(Event& event, GameWorld& world){
	Character& character = world.get_character(event.get_id());
	char weapon_type = event.get_msg()[1];
	std::unique_ptr<Weapon> weapon_buy(WeaponFactory::create(weapon_type));
	bool successful_buy = false;
	if (character.has_enough_to_buy(weapon_buy)) {
		if (character.has_optative_weapon()) {
			std::unique_ptr<Weapon> weapon(character.drop_optative_weapon());
			world.add_weapon(character.get_pos(), weapon.release());
		}
		character.buy_weapon(std::move(weapon_buy)); 
		successful_buy = true;
	} 
	world.get_step_info().add_buy(event.get_id(),
			 ClientTypeEvent::BUY_WEAPON, successful_buy);
}


BuyWeaponHandler::~BuyWeaponHandler(){}
