#include "StopPlantBombEvent.h"

StopPlantBombEvent::StopPlantBombEvent() {
  this->msg.push_back(ClientTypeEvent::STOP_PLANTING_BOMB);
}

StopPlantBombEvent::~StopPlantBombEvent() {}
