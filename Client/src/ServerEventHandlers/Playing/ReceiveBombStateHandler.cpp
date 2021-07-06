#include "ReceiveBombStateHandler.h"

ReceiveBombStateHandler::ReceiveBombStateHandler(){}

#include <iostream>
void ReceiveBombStateHandler::handle(FaseType& fase, Event& event, GameMap& map){
	/*
	fase = FaseType::PLAYING; 
	std::vector<char> event_msg = event.get_msg();
	BombState state = (BombState)event_msg[1];
	if (state == BombState::NORMAL) {
		bool has_owner = (bool)event_msg[2];
		if (has_owner) {
			char id_owner = event_msg[3];
			std::cout << id_owner << std::endl;
		} else {
			int x = *((int*)&(event_msg[3]));
			int y = *((int*)&(event_msg[7]));
			std::cout << x << y << std::endl;
		}
	} else if (state == BombState::ACTIVATING) {
		char id_owner = event_msg[2];
		char percentage = event_msg[3];
		std::cout << id_owner << percentage << std::endl;
	} else if (state == BombState::ACTIVATED) {
		char id_owner = event_msg[2];
		char time_until_explote = event_msg[3];
		int x = *((int*)&(event_msg[4]));
		int y = *((int*)&(event_msg[8]));
		std::cout << id_owner << time_until_explote << x << y << std::endl;
	} else if (state == BombState::DEACTIVATING) {
		char id_owner = event_msg[2];
		char percentage = event_msg[3];
		char time_until_explote = event_msg[4];
		std::cout << id_owner << percentage << time_until_explote << std::endl;

	}
	*/
}


ReceiveBombStateHandler::~ReceiveBombStateHandler(){}
