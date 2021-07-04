#include "StopDeactivateBombEvent.h"

StopDeactivateBombEvent::StopDeactivateBombEvent() {
  this->msg.push_back(ClientTypeEvent::STOP_DEACTIVATING_BOMB);
}

StopDeactivateBombEvent::~StopDeactivateBombEvent() {}
