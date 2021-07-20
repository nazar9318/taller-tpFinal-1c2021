#include "ReceiveInitConfigsHandler.h"
#include <iostream>
ReceiveInitConfigsHandler::ReceiveInitConfigsHandler() {}

void ReceiveInitConfigsHandler::handle(Event& event, GameMap& map, InitialPhase& initial_phase) {
    std::vector<char> event_msg = event.get_msg();
    int stencil_angle = *((int*)&(event_msg[1]));

    int stencil_radio = *((int*)&(event_msg[5]));

    int alpha_blending = *((int*)&(event_msg[9]));

    int init_money = *((int*)&(event_msg[13]));

    map.createStencil(stencil_angle, alpha_blending, stencil_radio);
    initial_phase.updateValues(-1, init_money, BuyState::SUCCESSFUL, 2, 0);

    int glock_bullets_price = *((int*)&(event_msg[17]));
    initial_phase.addPrice(glock_bullets_price, PositionType::PRIMARY_AMMO);


    auto it = event_msg.begin() + 21;
    while (it != event_msg.end()) {
    	PositionType type_weapon = (PositionType)*it;
    	int price = *((int*)&(*(it + 1)));
    	it += 5;
      initial_phase.addPrice(price, type_weapon);
    }
}

ReceiveInitConfigsHandler::~ReceiveInitConfigsHandler() {
}
