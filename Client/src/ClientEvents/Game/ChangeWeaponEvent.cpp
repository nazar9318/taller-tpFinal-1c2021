#include "ChangeWeaponEvent.h"


ChangeWeaponEvent::ChangeWeaponEvent(){
  this->msg.push_back(ClientTypeEvent::CHANGE_WEAPON);
}


ChangeWeaponEvent::~ChangeWeaponEvent(){}
