#include "ReceiveBuysHandler.h"

ReceiveBuysHandler::ReceiveBuysHandler() {
}
#include <iostream>
void ReceiveBuysHandler::handle(FaseType& fase, Event& event, GameMap& map, InitialPhase& initial_phase){
	std::vector<char> event_msg = event.get_msg();
	auto it = event_msg.begin() + 1;
	while(it != event_msg.end()) {
		char id = *it;
		char type_buy = *(it + 1);
		BuyState buy_state = (BuyState)*(it + 2);
		it += 2;
		int money = *((int*)&(*(it + 1)));
		char number_of_weapons = *(it + 5);
		int glock_bullets = *((int*)&(*(it + 6)));
		it += 10;
		std::cout << " COMPRA: ID " << (int)id
				  << " tipo de compra"  << (int)type_buy
				  << " successful " << (int)buy_state
				  << " money " << money
				  << " number_of_weapons " << (int)number_of_weapons
				  << " glock_bullets " << glock_bullets << std::endl;


		if (number_of_weapons == 3) {
			PositionType weapon_type = (PositionType)(*it);
			int bullets = *((int*)&(*(it + 1)));
			int bullets_price = *((int*)&(*(it + 5)));
			initial_phase.updateValues(money, buy_state, number_of_weapons, bullets_price);
			std::cout << "tercera weapon type :" << (int)weapon_type
			          << "con bullets: " << bullets << std::endl;
			it += 9;
		} else {

			initial_phase.updateValues(money, buy_state, number_of_weapons, NO_SECONDARY_AMMO);
		}
	}
}


ReceiveBuysHandler::~ReceiveBuysHandler() {
}
