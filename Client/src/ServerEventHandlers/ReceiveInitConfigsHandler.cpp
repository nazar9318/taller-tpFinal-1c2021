#include "ReceiveInitConfigsHandler.h"

ReceiveInitConfigsHandler::ReceiveInitConfigsHandler() {}
#include <iostream>
void ReceiveInitConfigsHandler::handle(Event& event, GameMap& map) {
    std::cout << "recibo configs"<<std::endl;
    std::vector<char> event_msg = event.get_msg();
    int glock_price = *((int*)&(event_msg[1]));
    int ak47_price = *((int*)&(event_msg[5]));;
    int m3_price = *((int*)&(event_msg[9]));
    int awp_price = *((int*)&(event_msg[13]));
    int stencil_angle = *((int*)&(event_msg[17]));
    std::cout << glock_price <<ak47_price<< m3_price << awp_price << stencil_angle << std::endl; 
}

ReceiveInitConfigsHandler::~ReceiveInitConfigsHandler() {
}
