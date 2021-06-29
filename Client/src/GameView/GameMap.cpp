#include "GameMap.h"



GameMap::GameMap(Renderer& renderer):renderer(renderer), tiles_textures(renderer) {}

void GameMap::create() {}

void GameMap::loadMedia(){
  syslog(LOG_INFO, "[%s:%i]: Por cargar las texturas de los Tiles",
                     __FILE__, __LINE__);
  tiles_textures.loadMedia();
}

void GameMap::addTile(Tile tile){
  tiles.push_back(std::move(tile));
}

void GameMap::setSize(int& width, int& height){
  map_width = width;
  map_height = height;
}

/*-------------------------Metodos para render----------------------------*/

void GameMap::renderGround(){

  SDL_Rect quad = {0};

  for (size_t i = 0; i < tiles.size(); i++) {
    Texture& texture(tiles_textures[tiles[i].getType()]);
    quad = tiles[i].getBox();
    renderer.render(texture.getTexture(), NULL, &quad);
  }
  syslog(LOG_INFO, "[%s:%i]: El ground fue renderizado",
                     __FILE__, __LINE__);
}





/*------------------------------------------------------------------------*/

GameMap::~GameMap() {}
