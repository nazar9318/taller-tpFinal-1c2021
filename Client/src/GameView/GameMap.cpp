#include "GameMap.h"

GameMap::GameMap(Renderer& renderer, ClientPlayer& player,
  Camera& camera, std::map<char, ClientCharacter> &characters, Hud& hud,
  FinalPhase& final_phase):
  renderer(renderer),
  tile_container(TileContainer::getInstance()),
  sprite_container(SpriteContainer::getInstance()),
  player(player),
  characters(characters),
  camera(camera),
  hud(hud),
  final_phase(final_phase){}

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



void GameMap::renderGround() {

  SDL_Rect quad = {0};

  for (size_t i = 0; i < tiles.size(); i++) {
    quad = tiles[i].getBox();
    if(camera.isVisible(quad)){
      Texture& texture(tiles[i].getTexture());
      camera.renderAddingOffset(texture.getTexture(), quad);
    }
  }
}

void GameMap::cleanWeapons() {
  weapons.clear();
}

void GameMap::renderWeapons() {
  SDL_Rect quad = {0};
  for (size_t i = 0; i < weapons.size(); i++) {
    quad = weapons[i].getBox();
    if(camera.isVisible(quad)){
      Texture& texture(weapons[i].getTexture());
      camera.renderAddingOffset(texture.getTexture(), quad);
    }
  }
}

void GameMap::update_position(char id, int pos_x, int pos_y, int angle,
        char life, int money, char weapon_type, int ammo) {
  if (id == player.get_id()) {
    player.update_position(pos_x, pos_y, angle, life, money, weapon_type, ammo);
    hud.update_values(life, money, ammo, weapon_type, player.has_bomb());
    camera.center(player.getBox(), map_width, map_height);
  } else {
    characters.at(id).update_position(pos_x, pos_y, angle, weapon_type);
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
  player.render(camera);
}


void GameMap::renderCharacters() {
  SDL_Rect quad = {0};
  for(auto it = characters.begin(); it != characters.end(); ++it){
    quad = it->second.getBox();
    if(camera.isVisible(quad)){
      it->second.render(camera);
    }
  }
}


void GameMap::add_stats(char id, int kills_round, int kills_total) {
  std::string name;
  std::string team;
  if (id == player.get_id()) {
    name = player.get_name();
    team = player.getTeam();
  } else {
    name = characters.at(id).get_name();
    team = characters.at(id).getTeam();
  }
  final_phase.addScore(name, team, kills_round, kills_total);
}



/*------------------------------------------------------------------------*/

GameMap::~GameMap() {}
