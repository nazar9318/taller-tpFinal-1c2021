#include "Tile.h"

Tile::Tile(int x, int y, char _type):texture(TileContainer::getInstance()[_type]) {
  box.x = x;
  box.y = y;
  box.w = TILE_WIDTH;
  box.h = TILE_HEIGHT;
  type = _type;
}

SDL_Rect& Tile::getBox() {
  return box;
}

char Tile::getType() {
  return type;
}

Texture& Tile::getTexture() {
  return texture;
}

Tile::~Tile() {}
