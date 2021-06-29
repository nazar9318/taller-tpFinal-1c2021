#include "TileContainer.h"

TileContainer::TileContainer(Renderer& renderer):renderer(renderer){}

void TileContainer::loadMedia(){

}

const Texture& TileContainer::operator[](const char id) const {

  if (container.find(id) != container.end()){
    throw Exception("No existe un tile para la clave %c", id);
  }
  return container.at(id);
}


TileContainer::~TileContainer(){}
