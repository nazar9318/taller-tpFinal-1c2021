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

  container[PositionType::AZTEC].loadFromFile(renderer, TILE_AZTEC_PATH);
  container[PositionType::INFERNO].loadFromFile(renderer, TILE_INFERNO_PATH);
  container[PositionType::DUST].loadFromFile(renderer, TILE_DUST_PATH);

  container[PositionType::BOMB_AREA_A].loadFromFile(renderer, TILE_BOMB_A_PATH);
  container[PositionType::BOMB_AREA_B].loadFromFile(renderer, TILE_BOMB_B_PATH);
  container[PositionType::BOMB_AREA_C].loadFromFile(renderer, TILE_BOMB_C_PATH);

  container[PositionType::BOX_BLACK].loadFromFile(renderer, TILE_BOX_BLACK_PATH);
  container[PositionType::BOX_BROWN].loadFromFile(renderer, TILE_BOX_BROWN_PATH);
  container[PositionType::BOX_METAL].loadFromFile(renderer, TILE_BOX_METAL_PATH);
  container[PositionType::BOX_WOOD_METAL].loadFromFile(renderer, TILE_BOX_WOOD_METAL_PATH);
  container[PositionType::BOX_WOOD].loadFromFile(renderer, TILE_BOX_WOOD_PATH);



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
