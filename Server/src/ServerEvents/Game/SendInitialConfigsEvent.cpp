#include "SendInitialConfigsEvent.h"
#include <iostream>
SendInitialConfigsEvent::SendInitialConfigsEvent() {
	this->msg.push_back((char)ModelTypeEvent::INITIAL_CONFIGS);
	
	int stencil_angle = CF::stencil_angle;
	push_back(stencil_angle);
	
	int glock_bullets_price = CF::glock_10_bullets_price;	
	push_back(glock_bullets_price);

	int ak47_price = CF::ak47_price;
	int m3_price = CF::m3_price;
	int awp_price = CF::awp_price;
	
	int ak47_bullets_price = CF::ak47_10_bullets_price;
	int m3_bullets_price = CF::m3_10_bullets_price;
	int awp_bullets_price = CF::awp_10_bullets_price;	
	
	msg.push_back(PositionType::AK47);
	push_back(ak47_price);
	push_back(ak47_bullets_price);
	
	msg.push_back(PositionType::M3);
	push_back(m3_price);
	push_back(m3_bullets_price);
	
	msg.push_back(PositionType::AWP);
	push_back(awp_price);
	push_back(awp_bullets_price);

	
}

SendInitialConfigsEvent::~SendInitialConfigsEvent() {

}

