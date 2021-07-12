#include "ReceivePlayingStepHandler.h"

ReceivePlayingStepHandler::ReceivePlayingStepHandler(){}


void ReceivePlayingStepHandler::handle(FaseType& fase, Event& event, GameMap& map){
	//fase = FaseType::PLAYING;
	std::vector<char> event_msg = event.get_msg();
	for (auto it = event_msg.begin() + 1; it != event_msg.end(); it += 23) {
		char id = *it;
		int pos_x = *((int*)&(*(it + 1)));
		int pos_y = *((int*)&(*(it + 5)));
	  int angle = *((int*)&(*(it + 9)));
    char life = *(it + 13);
		int money = *((int*)&(*(it + 14)));
		char weapon_type = *(it + 18);
		int ammo = *((int*)&(*(it + 19)));
		map.update_position(id, pos_x, pos_y, angle, life, money, weapon_type, ammo);
	}
}


ReceivePlayingStepHandler::~ReceivePlayingStepHandler(){}
