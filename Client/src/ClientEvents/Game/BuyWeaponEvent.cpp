#include "BuyWeaponEvent.h"

BuyWeaponEvent::BuyWeaponEvent(char weapon){
  this->msg.push_back(ClientTypeEvent::BUY_WEAPON);
  this->msg.push_back(weapon);
}


BuyWeaponEvent::~BuyWeaponEvent(){}
