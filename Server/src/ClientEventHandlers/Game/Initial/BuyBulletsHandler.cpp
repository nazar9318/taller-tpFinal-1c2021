#include "BuyBulletsHandler.h"

BuyBulletsHandler::BuyBulletsHandler() {}

void BuyBulletsHandler::handle(Event& event, GameWorld& world){
	Character& character = world.get_character(event.get_id());
	char type_ammo = event.get_msg()[1];
	bool successful_buy = character.buy(type_ammo);
	if (successful_buy) {
		//
	}
}


BuyBulletsHandler::~BuyBulletsHandler(){}
