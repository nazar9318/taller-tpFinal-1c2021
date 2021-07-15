#include "ReceiveInitConfigsHandler.h"
#include <iostream>
ReceiveInitConfigsHandler::ReceiveInitConfigsHandler() {}

void ReceiveInitConfigsHandler::handle(Event& event, GameMap& map, InitialPhase& initial_phase) {
    std::vector<char> event_msg = event.get_msg();
    int stencil_angle = *((int*)&(event_msg[1]));
    map.createStencil(stencil_angle, 150);

    int glock_bullets_price = *((int*)&(event_msg[5]));
    std::cout << "stencil_angle: " << stencil_angle <<
            "glock_bullets_price " << glock_bullets_price << std::endl;

    auto it = event_msg.begin() + 9;
    while (it != event_msg.end()) {
    	PositionType type_weapon = (PositionType)*it;
    	int price = *((int*)&(*(it + 1)));
        int bullets_price = *((int*)&(*(it + 5)));
    	it += 9;
        initial_phase.addPrice(price, type_weapon);
    	std::cout << "type: " << (int)type_weapon <<
                     "price " << bullets_price << std::endl;
    }
    initial_phase.addPrice(50, PositionType::PRIMARY_AMMO);
    initial_phase.addPrice(50, PositionType::SECONDARY_AMMO);
}

ReceiveInitConfigsHandler::~ReceiveInitConfigsHandler() {
}
