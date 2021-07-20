#include "WeaponSprite.h"
#include <iostream>

WeaponSprite::WeaponSprite(int x, int y, char _type) :
texture(SpriteContainer::getInstance()[_type]) {
  box.w = texture.get_w();
  box.h = texture.get_h();
  box.x = x - box.w /2;
  box.y = y - box.h /2;
  type = _type;
}

SDL_Rect& WeaponSprite::getBox() { return box; }

char WeaponSprite::getType() { return type; }

Texture& WeaponSprite::getTexture() { return texture; }

WeaponSprite::~WeaponSprite() {}
