#include "TileContainer.h"

std::unique_ptr<TileContainer> TileContainer::instance = 0;

TileContainer::TileContainer(){}

TileContainer& TileContainer::getInstance(){
  if(!instance){
    instance.reset(new TileContainer());
  }
  return *instance;
}

void TileContainer::loadMedia(Renderer& renderer){

  container[PositionType::AZTEC].loadFromFile(renderer, "../Client/Assets/Tiles/aztec.png");
  container[PositionType::INFERNO].loadFromFile(renderer, "../Client/Assets/Tiles/inferno.png");
  container[PositionType::DUST].loadFromFile(renderer, "../Client/Assets/Tiles/dust.png");

  container[PositionType::BOMB_AREA_A].loadFromFile(renderer, "../Client/Assets/Tiles/bomb_area_a.png");
  container[PositionType::BOMB_AREA_B].loadFromFile(renderer, "../Client/Assets/Tiles/bomb_area_b.png");
  container[PositionType::BOMB_AREA_C].loadFromFile(renderer, "../Client/Assets/Tiles/bomb_area_c.png");

  container[PositionType::BOX_BLACK].loadFromFile(renderer, "../Client/Assets/Tiles/box_black.png");
  container[PositionType::BOX_BROWN].loadFromFile(renderer, "../Client/Assets/Tiles/box_brown.png");
  container[PositionType::BOX_METAL].loadFromFile(renderer, "../Client/Assets/Tiles/box_metal.png");
  container[PositionType::BOX_WOOD_METAL].loadFromFile(renderer, "../Client/Assets/Tiles/box_wood_metal.png");
  container[PositionType::BOX_WOOD].loadFromFile(renderer, "../Client/Assets/Tiles/box_wood.png");



  syslog(LOG_INFO, "[%s:%i]: Texturas de los tiles cargadas",
                     __FILE__, __LINE__);

}

Texture& TileContainer::operator[](char id){

  /*syslog(LOG_INFO, "[%s:%i]: Buscando la textura para el id %c",
  __FILE__, __LINE__, id);*/

  if (container.find(id) == container.end()){
    throw Exception("No existe un tile para la clave %c", id);
  }
  return container[id];
}


TileContainer::~TileContainer(){}
