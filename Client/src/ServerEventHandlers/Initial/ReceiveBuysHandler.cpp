#include "ReceiveBuysHandler.h"

ReceiveBuysHandler::ReceiveBuysHandler() {
}

void ReceiveBuysHandler::handle(FaseType& fase, Event& event, GameMap& map){
	/*
	std::vector<char> event_msg = event.get_msg();
	auto it = event_msg.begin() + 1;
	while(it != event_msg.end()) {
		char id = *it;
		int money = *((int*)&(*(it + 1)));
		char number_of_weapons = *(it + 5);
		int glock_bullets = *((int*)&(*(it + 6)));
		it += 7;
		if (number_of_weapons == 3) {
			PositionType weapon_type = (PositionType)(*it);
			int bullets = *((int*)&(*(it + 1)));
			it += 5;
		}
	}*/
}


ReceiveBuysHandler::~ReceiveBuysHandler() {
}
