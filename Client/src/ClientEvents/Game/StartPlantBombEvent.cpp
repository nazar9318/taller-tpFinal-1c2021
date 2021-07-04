#include "StartPlantBombEvent.h"

StartPlantBombEvent::StartPlantBombEvent(){
  this->msg.push_back(ClientTypeEvent::START_PLANTING_BOMB);
}

StartPlantBombEvent::~StartPlantBombEvent(){}
