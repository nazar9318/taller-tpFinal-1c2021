#include "GameMap.h"



GameMap::GameMap(Renderer& renderer):renderer(renderer), tile_container(TileContainer::getInstance()),
                                    sprite_container(SpriteContainer::getInstance()){}

void GameMap::create() {}

void GameMap::loadMedia(){
  syslog(LOG_INFO, "[%s:%i]: Por cargar las texturas de los Tiles",
                     __FILE__, __LINE__);
  tile_container.loadMedia(renderer);
  syslog(LOG_INFO, "[%s:%i]: Por cargar las texturas de los Sprites",
                    __FILE__, __LINE__);
  sprite_container.loadMedia(renderer);
}

void GameMap::addTile(Tile tile){
  tiles.push_back(std::move(tile));
}

void GameMap::addWeapon(WeaponSprite weapon){
  weapons.push_back(std::move(weapon));
}

void GameMap::setSize(int& width, int& height){
  map_width = width;
  map_height = height;
}

/*-------------------------Metodos para render----------------------------*/

void GameMap::cleanWeapons(){
  weapons.clear();
}

void GameMap::renderGround(){

  SDL_Rect quad = {0};

  for (size_t i = 0; i < tiles.size(); i++) {
    Texture& texture(tiles[i].getTexture());
    quad = tiles[i].getBox();
    renderer.render(texture.getTexture(), NULL, &quad);
  }
  // syslog(LOG_INFO, "[%s:%i]: El ground fue renderizado",
  //                    __FILE__, __LINE__);
}

void GameMap::renderWeapons(){

  SDL_Rect quad = {0};

  for (size_t i = 0; i < weapons.size(); i++) {
    Texture& texture(weapons[i].getTexture());
    quad = weapons[i].getBox();
    renderer.render(texture.getTexture(), NULL, &quad);
  }
  // syslog(LOG_INFO, "[%s:%i]: Los Weapons fueron renderizados",
  //                    __FILE__, __LINE__);
}





/*------------------------------------------------------------------------*/

GameMap::~GameMap() {}
