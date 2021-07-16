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
  container[PositionType::AWP].loadFromFile(renderer, SPRITE_AWP_PATH, weapons_color);
  container[PositionType::M3].loadFromFile(renderer, SPRITE_M3_PATH, weapons_color);
  container[PositionType::AK47].loadFromFile(renderer, SPRITE_AK47_PATH, weapons_color);
  container[PositionType::GLOCK].loadFromFile(renderer, SPRITE_GLOCK_PATH, weapons_color);
  container[PositionType::KNIFE].loadFromFile(renderer, SPRITE_KNIFE_PATH, black_color);
  container[PositionType::BOMB].loadFromFile(renderer, SPRITE_BOMB_PATH, black_color);

  /*Aca tambien cargariamos las texturas de los players*/
  container[Team::TERRORIST].loadFromFile(renderer, SPRITE_NPC_T2_PATH, black_color);
  container[Team::COUNTER_ENEMY].loadFromFile(renderer, SPRITE_NPC_CT2_PATH, black_color);

  container[Equipped_Weapon::KNIFE_EQUIPPED].loadFromFile(renderer, SPRITE_NPC_KNIFE_PATH, black_color);
  container[Equipped_Weapon::GLOCK_EQUIPPED].loadFromFile(renderer, SPRITE_NPC_GLOCK_PATH, black_color);
  container[Equipped_Weapon::M3_EQUIPPED].loadFromFile(renderer, SPRITE_NPC_M3_PATH, black_color);
  container[Equipped_Weapon::AK47_EQUIPPED].loadFromFile(renderer, SPRITE_NPC_AK47_PATH, black_color);
  container[Equipped_Weapon::AWP_EQUIPPED].loadFromFile(renderer, SPRITE_NPC_AWP_PATH, black_color);

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
