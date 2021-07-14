#include "ReceiveBuysHandler.h"

ReceiveBuysHandler::ReceiveBuysHandler() {
}
#include <iostream>
void ReceiveBuysHandler::handle(FaseType& fase, Event& event, GameMap& map){
	std::vector<char> event_msg = event.get_msg();
	auto it = event_msg.begin() + 1;
	while(it != event_msg.end()) {
		char id = *it;
		char type_buy = *(it + 1);
		bool successful = (bool)*(it + 2);
		it += 2;
		int money = *((int*)&(*(it + 1)));
		char number_of_weapons = *(it + 5);
		int glock_bullets = *((int*)&(*(it + 6)));
		it += 10;
		std::cout << " COMPRA: ID " << (int)id
				  << " tipo de compra"  << (int)type_buy 
				  << " successful " << successful 
				  << " money " << money 
				  << " number_of_weapons " << (int)number_of_weapons 
				  << " glock_bullets " << glock_bullets << std::endl;

		if (number_of_weapons == 3) {
			PositionType weapon_type = (PositionType)(*it);
			int bullets = *((int*)&(*(it + 1)));
			std::cout << "tercera weapon type :" << (int)weapon_type 
			          << "con bullets: " << bullets << std::endl;
			it += 5;
		}
	}
}


ReceiveBuysHandler::~ReceiveBuysHandler() {
}
