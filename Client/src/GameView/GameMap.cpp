#include "GameMap.h"

GameMap::GameMap(Renderer& renderer, ClientPlayer& player, Camera& camera, std::map<char,
          ClientCharacter> &characters, Hud& hud)
: renderer(renderer), tile_container(TileContainer::getInstance()),
sprite_container(SpriteContainer::getInstance()), player(player),
characters(characters), camera(camera), hud(hud) {}

void GameMap::create() {}

void GameMap::loadMedia() {
  syslog(LOG_INFO, "[%s:%i]: Por cargar las texturas de los Tiles",
                     __FILE__, __LINE__);
  tile_container.loadMedia(renderer);
  syslog(LOG_INFO, "[%s:%i]: Por cargar las texturas de los Sprites",
                    __FILE__, __LINE__);
  sprite_container.loadMedia(renderer);
}

void GameMap::addTile(Tile tile) {
  tiles.push_back(std::move(tile));
}

void GameMap::addWeapon(WeaponSprite weapon) {
  weapons.push_back(std::move(weapon));
}

void GameMap::setSize(int& width, int& height) {
  map_width = width;
  map_height = height;
}

/*-------------------------Metodos para render----------------------------*/

void GameMap::cleanWeapons() {
  weapons.clear();
}

void GameMap::renderGround() {

  SDL_Rect quad = {0};

  for (size_t i = 0; i < tiles.size(); i++) {
    Texture& texture(tiles[i].getTexture());
    quad = tiles[i].getBox();
    renderer.render(texture.getTexture(), NULL, &quad);
  }
}

void GameMap::renderWeapons() {
  SDL_Rect quad = {0};
  for (size_t i = 0; i < weapons.size(); i++) {
    Texture& texture(weapons[i].getTexture());
    quad = weapons[i].getBox();
    renderer.render(texture.getTexture(), NULL, &quad);
  }

}

void GameMap::update_position(char id, int pos_x, int pos_y, int angle, char life, int money, char weapon_type, int ammo) {
  if (id == player.get_id()) {
    player.update_position(pos_x, pos_y, angle, life, money);
    hud.update_values(life, money);
    // camera.center(player.getBox(), map_width, map_height);
  } else {
    characters.at(id).update_position(pos_x, pos_y, angle);
  }
}

void GameMap::add_character_team(char id, Team team) {
  if (id == player.get_id()) {
    player.set_team(team);
  } else {
    characters.at(id).set_team(team);
  }
}

void GameMap::renderPlayer() {
  Texture& texture(player.getTexture());
  double angle = player.getAngle();
  SDL_RenderCopyEx(renderer.getRenderer(), texture.getTexture(),
                  &player.getClip(), &player.getBox(), angle, NULL, SDL_FLIP_NONE);
  //renderer.render(texture.getTexture(), NULL, &quad, angle);
}

void GameMap::renderCharacters() {
  SDL_Rect quad = {0};
  double angle = 0;

  for(auto it = characters.begin(); it != characters.end(); ++it){
    Texture& texture(it->second.getTexture());
    quad = it->second.getBox();
    angle = it->second.getAngle();
    renderer.render(texture.getTexture(), NULL, &quad, angle);
  }
}

/*------------------------------------------------------------------------*/

GameMap::~GameMap() {}
