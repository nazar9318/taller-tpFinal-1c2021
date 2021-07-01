#include "ModelEventHandler.h"


ModelEventHandler::ModelEventHandler() {}

void ModelEventHandler::handle(Event& event, GameMap& map) {

  switch (event.get_type()) {
    case ModelTypeEvent::SEND_FULL_MAP:
      recive_map.handle(event, map);
      // syslog(LOG_INFO, "[%s:%i]: Manejo el evento recibir mapa",
      // 									 __FILE__, __LINE__);
      break;

    case ModelTypeEvent::SEND_WEAPONS:
      recive_weapons.handle(event, map);
      break;
      
    default:
      break;
  }
}


ModelEventHandler::~ModelEventHandler() {}
