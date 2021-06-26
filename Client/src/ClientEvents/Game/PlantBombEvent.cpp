#include "PlantBombEvent.h"

PlantBombEvent::PlantBombEvent(){
  this->msg.push_back(ClientTypeEvent::PLANT_BOMB);
}

PlantBombEvent::~PlantBombEvent(){}
