#include "SendInitialConfigsEvent.h"
#include <iostream>
SendInitialConfigsEvent::SendInitialConfigsEvent() {
	this->msg.push_back((char)ModelTypeEvent::INITIAL_CONFIGS);
	
	int glock_price = CF::glock_price;
	int ak47_price = CF::ak47_price;
	int m3_price = CF::m3_price;
	int awp_price = CF::awp_price;

	push_back(glock_price);
	push_back(ak47_price);
	push_back(m3_price);
	push_back(awp_price);

	int stencil_angle = CF::stencil_angle;
	push_back(stencil_angle);
}

SendInitialConfigsEvent::~SendInitialConfigsEvent() {

}

