#include "DropWeaponEvent.h"

DropWeaponEvent::DropWeaponEvent(){
  this->msg.push_back(ClientTypeEvent::DROP_WEAPON);
}


DropWeaponEvent::~DropWeaponEvent(){}
