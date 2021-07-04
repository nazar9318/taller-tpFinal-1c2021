#include "StartDeactivateBombEvent.h"

StartDeactivateBombEvent::StartDeactivateBombEvent() {
  this->msg.push_back(ClientTypeEvent::START_DEACTIVATING_BOMB);
}

StartDeactivateBombEvent::~StartDeactivateBombEvent() {}
