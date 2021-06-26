#include "DeactivateBombEvent.h"

DeactivateBombEvent::DeactivateBombEvent(){
  this->msg.push_back(ClientTypeEvent::DEACTIVATE_BOMB);
}


DeactivateBombEvent::~DeactivateBombEvent(){}
