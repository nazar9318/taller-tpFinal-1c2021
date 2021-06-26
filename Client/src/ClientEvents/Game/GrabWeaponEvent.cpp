#include "GrabWeaponEvent.h"

GrabWeaponEvent::GrabWeaponEvent(){
  this->msg.push_back(ClientTypeEvent::GRAB_WEAPON);
}

GrabWeaponEvent::~GrabWeaponEvent(){}
