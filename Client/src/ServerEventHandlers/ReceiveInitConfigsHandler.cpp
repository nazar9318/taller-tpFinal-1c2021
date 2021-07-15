#include "ReceiveInitConfigsHandler.h"
#include <iostream>
ReceiveInitConfigsHandler::ReceiveInitConfigsHandler() {}

void ReceiveInitConfigsHandler::handle(Event& event, GameMap& map, InitialPhase& initial_phase) {
    std::vector<char> event_msg = event.get_msg();
    int stencil_angle = *((int*)&(event_msg[1]));
    
    int stencil_radio = *((int*)&(event_msg[5]));

    int alpha_blending = *((int*)&(event_msg[9]));

    int init_money = *((int*)&(event_msg[13]));

    std::cout << "stencil_radio: " << stencil_radio <<
            "init_money " << init_money << std::endl;


    map.createStencil(stencil_angle, alpha_blending);

    int glock_bullets_price = *((int*)&(event_msg[17]));
    std::cout << "stencil_angle: " << stencil_angle <<
            "glock_bullets_price " << glock_bullets_price << std::endl;

    auto it = event_msg.begin() + 21;
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
