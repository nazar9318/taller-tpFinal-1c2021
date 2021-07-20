#include "ReceiveInitPlayersHandler.h"

ReceiveInitPlayersHandler::ReceiveInitPlayersHandler(){}


void ReceiveInitPlayersHandler::handle(FaseType& fase,
				Event& event, GameMap& map, InitialPhase& initial_phase) {
	fase = FaseType::INITIAL_FASE;
	std::vector<char> event_msg = event.get_msg();
	auto it = event_msg.begin() + 1;
	while(it != event_msg.end()) {
		char id = *it;
		Team team = (Team)*(it + 1);
		map.add_character_team(id, team);

		int money = *((int*)&(*(it + 2)));
		char number_of_weapons = *(it + 6);
		// int glock_bullets = *((int*)&(*(it + 7)));
		it += 11;

		if (number_of_weapons == 3) {
			// PositionType weapon_type = (PositionType)(*it);
			// int bullets = *((int*)&(*(it + 1)));
			int bullets_price = *((int*)&(*(it + 5)));
			initial_phase.updateValues(id, money, BuyState::SUCCESSFUL,
								 number_of_weapons, bullets_price);

			it += 9;
		} else {
			initial_phase.updateValues(id, money, BuyState::SUCCESSFUL, number_of_weapons,
																 NO_SECONDARY_AMMO);
		}
	}
}


ReceiveInitPlayersHandler::~ReceiveInitPlayersHandler(){}
