#include "ReceiveInitConfigsHandler.h"

ReceiveInitConfigsHandler::ReceiveInitConfigsHandler() {}
#include <iostream>
void ReceiveInitConfigsHandler::handle(Event& event, GameMap& map) {
    std::vector<char> event_msg = event.get_msg();
    int stencil_angle = *((int*)&(event_msg[1]));
    std::cout << "stencil_angle: " << stencil_angle << std::endl;

    auto it = event_msg.begin() + 5;
    while (it != event_msg.end()) {
    	PositionType type_weapon = (PositionType)*it;
    	int price = *((int*)&(*(it + 1)));
    	it += 5;
    	std::cout << "type: " << (int)type_weapon << "price " << price << std::endl;
    }
}

ReceiveInitConfigsHandler::~ReceiveInitConfigsHandler() {
}
