#include "WeaponSprite.h"
#include <iostream>

WeaponSprite::WeaponSprite(int x, int y, char _type):texture(SpriteContainer::getInstance()[_type]){
  box.x = x;
  box.y = y;
  box.w = texture.get_w();
  box.h = texture.get_h();
  type = _type;
}

SDL_Rect& WeaponSprite::getBox(){
  return box;
}

char WeaponSprite::getType(){
  return type;
}

Texture& WeaponSprite::getTexture(){
  return texture;
}

WeaponSprite::~WeaponSprite(){}
