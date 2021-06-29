#include "TileContainer.h"

#define TILES_PATH "../Client/Assets/Tiles/"

TileContainer::TileContainer(Renderer& renderer):renderer(renderer){}

void TileContainer::loadMedia(){

  Texture texture;
  texture.loadFromFile(renderer, "../Client/Assets/Tiles/aztec.png");

  container.insert({PositionType::INFERNO, std::move(texture)});
  // container[PositionType::AZTEC].loadFromFile(renderer, "../Client/Assets/Tiles/aztec.png");
  // container[PositionType::INFERNO].loadFromFile(renderer, "../Client/Assets/Tiles/inferno.png");
  // container[PositionType::DUST].loadFromFile(renderer, "../Client/Assets/Tiles/dust.png");

  syslog(LOG_INFO, "[%s:%i]: Texturas de los tiles cargadas",
                     __FILE__, __LINE__);

}

Texture& TileContainer::operator[](const char id){

  syslog(LOG_INFO, "[%s:%i]: Buscando la textura para el id %c",
  __FILE__, __LINE__, id);

  if (container.find(id) != container.end()){
    throw Exception("No existe un tile para la clave %c", id);
  }
  return container[id];
}


TileContainer::~TileContainer(){}
