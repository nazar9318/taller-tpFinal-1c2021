#include "BuyBulletsEvent.h"

BuyBulletsEvent::BuyBulletsEvent(char weapon){
  this->msg.push_back(ClientTypeEvent::BUY_BULLETS);
  this->msg.push_back(weapon);
}


BuyBulletsEvent::~BuyBulletsEvent(){}
