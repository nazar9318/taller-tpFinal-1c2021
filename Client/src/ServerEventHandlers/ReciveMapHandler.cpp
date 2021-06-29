#include "ReciveMapHandler.h"

ReciveMapHandler::ReciveMapHandler(){}

void ReciveMapHandler::handle(Event& event, GameMap& map){
  //El msg tiene --> typo/width/height/pox/posy/block
  std::vector<char> event_msg = event.get_msg();

  int width = *((int*)&(event_msg[1]));
  int height = *((int*)&(event_msg[5]));
  map.setSize(width, height);

  char type;
  int x,y;

  for (size_t i = 9; i < event_msg.size(); i+=9) {
    x = *((int*)&(event_msg[i]));
    y = *((int*)&(event_msg[i+4]));
    type = event_msg[i+8];
    Tile tile(x, y, type);
    map.addTile(std::move(tile));
  }

  syslog(LOG_INFO, "[%s:%i]: Toda la info del mapa fue cargada en los tiles",
                     __FILE__, __LINE__);


}

ReciveMapHandler::~ReciveMapHandler(){}
