#include "SendInitialConfigsEvent.h"
#include <iostream>
SendInitialConfigsEvent::SendInitialConfigsEvent() {
	this->msg.push_back((char)ModelTypeEvent::INITIAL_CONFIGS);
	
	int stencil_angle = CF::stencil_angle;
	push_back(stencil_angle);
	
	int ak47_price = CF::ak47_price;
	int m3_price = CF::m3_price;
	int awp_price = CF::awp_price;
		
	msg.push_back(PositionType::AK47);
	push_back(ak47_price);
	
	msg.push_back(PositionType::M3);
	push_back(m3_price);
	
	msg.push_back(PositionType::AWP);
	push_back(awp_price);

}

SendInitialConfigsEvent::~SendInitialConfigsEvent() {

}

