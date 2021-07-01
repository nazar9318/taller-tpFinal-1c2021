#include "SpriteContainer.h"

std::unique_ptr<SpriteContainer> SpriteContainer::instance = 0;

SpriteContainer::SpriteContainer() {}

SpriteContainer& SpriteContainer::getInstance() {
  if (!instance) {
    instance.reset(new SpriteContainer());
  }
  return *instance;
}

void SpriteContainer::loadMedia(Renderer& renderer) {
  Color weapons_color = {0xFF, 0x00, 0xFF};
  Color black_color = {0x00, 0x00, 0x00};

  /*Aca tambien cargariamos las texturas de las armas*/
  container[PositionType::AWP].loadFromFile(renderer, "../Client/Assets/Sprites/Weapons/awp.bmp", weapons_color);
  container[PositionType::M3].loadFromFile(renderer, "../Client/Assets/Sprites/Weapons/m3.bmp", weapons_color);
  container[PositionType::AK47].loadFromFile(renderer, "../Client/Assets/Sprites/Weapons/ak47.bmp", weapons_color);
  container[PositionType::GLOCK].loadFromFile(renderer, "../Client/Assets/Sprites/Weapons/glock.bmp", weapons_color);
  container[PositionType::KNIFE].loadFromFile(renderer, "../Client/Assets/Sprites/Weapons/knife.bmp", black_color);
  container[PositionType::BOMB].loadFromFile(renderer, "../Client/Assets/Sprites/Weapons/bomb.bmp", black_color);

  /*Aca tambien cargariamos las texturas de los players*/
  container[Team::TERRORIST].loadFromFile(renderer, "../Client/Assets/NPC/t1.bmp", black_color);
  container[Team::COUNTER_ENEMY].loadFromFile(renderer, "../Client/Assets/NPC/ct1.bmp", black_color);
 
  syslog(LOG_INFO, "[%s:%i]: Texturas de los sprites cargadas", __FILE__, __LINE__);
}

Texture& SpriteContainer::operator[](char id) {
  /*syslog(LOG_INFO, "[%s:%i]: Buscando la textura para el id %c",
  __FILE__, __LINE__, id);*/

  if (container.find(id) == container.end()) {
    throw Exception("No existe un sprite para la clave %c", id);
  }
  return container[id];
}

SpriteContainer::~SpriteContainer() {}
