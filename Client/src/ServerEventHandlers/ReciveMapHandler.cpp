#include "ReciveMapHandler.h"
#include <iostream>

ReciveMapHandler::ReciveMapHandler(){}

void ReciveMapHandler::handle(Event& event, GameMap& map){
  //El msg tiene --> typo/width/height/pox/posy/block
  // map.setSize();
  // std::vector<char> event_msg = event.get_msg();
  //
  // int w = (int)event_msg[0];
  // std::cout << "El width del mapa es " << w  << '\n';
}

ReciveMapHandler::~ReciveMapHandler(){}
