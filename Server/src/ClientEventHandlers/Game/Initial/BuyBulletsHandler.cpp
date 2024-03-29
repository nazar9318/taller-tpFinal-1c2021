#include "BuyBulletsHandler.h"

BuyBulletsHandler::BuyBulletsHandler() {}

void BuyBulletsHandler::handle(Event& event, GameWorld& world){
	Character& character = world.get_character(event.get_id());
	char type_ammo = event.get_msg()[1];
	
	BuyState buy_state = character.buy(type_ammo);
	world.get_step_info().add_buy(event.get_id(),
						 ClientTypeEvent::BUY_BULLETS, buy_state);
}


BuyBulletsHandler::~BuyBulletsHandler(){}
