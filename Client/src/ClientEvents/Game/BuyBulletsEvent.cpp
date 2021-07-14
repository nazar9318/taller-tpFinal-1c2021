#include "BuyBulletsEvent.h"

BuyBulletsEvent::BuyBulletsEvent(char kind_of_ammo){
  this->msg.push_back(ClientTypeEvent::BUY_BULLETS);
  this->msg.push_back(kind_of_ammo);
}


BuyBulletsEvent::~BuyBulletsEvent(){}
