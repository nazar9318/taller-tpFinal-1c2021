#include "ModelEventHandler.h"


ModelEventHandler::ModelEventHandler() {}

void ModelEventHandler::handle(FaseType& fase, Event& event, GameMap& map) {
  //while()
  switch (event.get_type()) {
    case ModelTypeEvent::SEND_FULL_MAP:
      recive_map.handle(event, map);
      break;

    case ModelTypeEvent::SEND_WEAPONS:
      recive_weapons.handle(event, map);
      break;

    case ModelTypeEvent::STEP_INFO:
      recive_step.handle(fase, event, map);
      break;

    default:
      break;
  }
}


ModelEventHandler::~ModelEventHandler() {}
