#include "ReceiveAttacksHandler.h"
#include <iostream>

ReceiveAttacksHandler::ReceiveAttacksHandler(){}

void ReceiveAttacksHandler::handle(FaseType& fase, Event& event, GameMap& map, AttackEffect& attack_effects) {
	//fase = FaseType::PLAYING;
	std::vector<char> event_msg = event.get_msg();
	int number_attacks = (int)event_msg[1];
	int iterator = 2;
	if (number_attacks > 0)
		std::cout << "Hay " << number_attacks<<"ataques"<< std::endl;
	for (int i = 0; i < number_attacks; i++) {
		char id_attacker = event_msg[iterator];
		PositionType weapon = (PositionType)event_msg[iterator + 1];
		std::cout << "Ataca: " << (int)id_attacker <<
						 " con weapon: " << (int)weapon << std::endl;
		int number_receivers = (int)event_msg[iterator + 2];
		iterator += 3;

		for (int j = 0; j < number_receivers; j++) {
			char receiver_id = event_msg[iterator];
			attack_effects.createAttack(receiver_id, id_attacker);
			iterator++;
		}
	}
}


ReceiveAttacksHandler::~ReceiveAttacksHandler(){}
