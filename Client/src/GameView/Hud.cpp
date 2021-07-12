#include "Hud.h"


Hud::Hud(Renderer& renderer, int window_width, int window_height):renderer(renderer),
      window_width(window_width), window_height(window_height), time_to_explode(-1){}

void Hud::loadMedia(){
  Color black_color = {0x00, 0x00, 0x00};
  Color yellow = {0xFF, 0xFF, 0x00};

  numbers.loadFromFile(renderer, "../Client/Assets/Hud/hud_nums.bmp", black_color, SDL_BLENDMODE_BLEND, 150);
  hud_symbols.loadFromFile(renderer, "../Client/Assets/Hud/hud_symbols.bmp", black_color, SDL_BLENDMODE_BLEND, 150);

  weapons[PositionType::AK47].loadFromFile(renderer, "../Client/Assets/Hud/ak47_k.bmp", black_color, SDL_BLENDMODE_BLEND, 150);
  weapons[PositionType::M3].loadFromFile(renderer, "../Client/Assets/Hud/m3_k.bmp", black_color, SDL_BLENDMODE_BLEND, 150);
  weapons[PositionType::AWP].loadFromFile(renderer, "../Client/Assets/Hud/awp_k.bmp", black_color, SDL_BLENDMODE_BLEND, 150);
  weapons[PositionType::GLOCK].loadFromFile(renderer, "../Client/Assets/Hud/glock_k.bmp", black_color, SDL_BLENDMODE_BLEND, 150);
  weapons[PositionType::KNIFE].loadFromFile(renderer, "../Client/Assets/Hud/knife_k.bmp", black_color, SDL_BLENDMODE_BLEND, 150);

  hud_symbols.setColor(yellow);
  numbers.setColor(yellow);

  for (auto it = weapons.begin(); it != weapons.end(); ++it) {
    it->second.setColor(yellow);
  }

  setClips();
}

void Hud::setClips(){
  /*clips[0] -> life_symbol*/
  clips[0].x = 0;
  clips[0].y = 0;
  clips[0].w = 64;
  clips[0].h = 64;

  /*clips[1] -> money_symbol*/
  clips[1].x = 460;
  clips[1].y = 0;
  clips[1].w = 40;
  clips[1].h = 64;

  /*clips[2] -> infinity_symbol*/
  clips[2].x = 704;
  clips[2].y = 0;
  clips[2].w = 64;
  clips[2].h = 64;

  /*clips[3] -> bomb_symbol*/
  clips[3].x = 382;
  clips[3].y = 0;
  clips[3].w = 70;
  clips[3].h = 64;

  /*clips[4] -> clock_symbol*/
  clips[4].x = 128;
  clips[4].y = 0;
  clips[4].w = 64;
  clips[4].h = 64;

  /*clips[5] -> colon_symbol*/
  clips[5].x = 474;
  clips[5].y = 0;
  clips[5].w = 24;
  clips[5].h = NUMBERS_HEIGHT;

}

void Hud::update_values(char life, int money, int ammo, char weapon_type, bool has_bomb){
  this->life = (int)life;
  this->money = money;
  this->ammo = ammo;
  this->weapon_type = weapon_type;
  this->has_bomb = has_bomb;
}

void Hud::updateTimeToExplode(int time){
  time_to_explode = time;
}


int Hud::numbers_offset(std::string& string, int& i){
  int number = string[i] - 48;
  if(number != 0){
    return number*NUMBERS_WIDTH + number*NUMBERS_OFFSET;
  }
  return number*NUMBERS_WIDTH;
}

void Hud::renderLife(){
  std::string life_str = std::to_string(life);
  int offset = 0;
  int y_pos = window_height - NUMBERS_OFFSET - NUMBERS_HEIGHT;
  SDL_Rect clip = {0};
  SDL_Rect quad = {0};

  quad = {NUMBERS_OFFSET, y_pos, SYMBOL_WIDTH, SYMBOL_HEIGHT};
  renderer.render(hud_symbols.getTexture(), &clips[0], &quad);

  for (int i = 0; i < (int)life_str.length(); i++) {
    offset = numbers_offset(life_str, i);
    clip = {offset, 0, NUMBERS_WIDTH, NUMBERS_HEIGHT}; //Con esto obtengo el numero a renderizar
    quad = {i*NUMBERS_WIDTH + NUMBERS_OFFSET + SYMBOL_WIDTH, y_pos, NUMBERS_WIDTH, NUMBERS_HEIGHT};
    renderer.render(numbers.getTexture(), &clip, &quad);
  }

}

void Hud::renderMoney(){

  std::string money_str = std::to_string(money);

  int money_offset = 1;
  int offset = 0;
  int y_pos = window_height - NUMBERS_OFFSET - NUMBERS_HEIGHT;
  SDL_Rect clip = {0};
  SDL_Rect quad = {0};

  for (int i = (int)money_str.length() - 1; i >= 0; i--) {
    offset = numbers_offset(money_str, i);
    clip = {offset, 0, NUMBERS_WIDTH, NUMBERS_HEIGHT}; //Con esto obtengo el numero a renderizar

    quad = {window_width - NUMBERS_OFFSET - (money_offset)*NUMBERS_WIDTH, y_pos, NUMBERS_WIDTH, NUMBERS_HEIGHT};
    renderer.render(numbers.getTexture(), &clip, &quad);
    money_offset++;
  }

  quad = {window_width + NUMBERS_OFFSET - (money_offset)*NUMBERS_WIDTH, y_pos, NUMBERS_WIDTH, NUMBERS_HEIGHT};
  renderer.render(hud_symbols.getTexture(), &clips[1], &quad);

}

void Hud::renderAmmo(){

  std::string ammo_str = std::to_string(ammo);
  int offset = 0;
  int i = 0;
  int y_pos = window_height - NUMBERS_OFFSET - NUMBERS_HEIGHT;
  SDL_Rect clip = {0};
  SDL_Rect ammo_quad = {0};

  SDL_Rect quad = {AMMO_OFFSET, y_pos, SYMBOL_WIDTH, SYMBOL_HEIGHT};

  if(ammo == INIFNITY_AMMO){
    renderer.render(hud_symbols.getTexture(), &clips[2], &quad);
    ammo_quad = {AMMO_OFFSET + NUMBERS_OFFSET + SYMBOL_WIDTH, y_pos, NUMBERS_WIDTH, NUMBERS_HEIGHT};
  }

  if(ammo != INIFNITY_AMMO){
    for (i = 0; i < (int)ammo_str.length(); i++) {
      offset = numbers_offset(ammo_str, i);
      clip = {offset, 0, NUMBERS_WIDTH, NUMBERS_HEIGHT}; //Con esto obtengo el numero a renderizar
      quad = {i*NUMBERS_WIDTH + NUMBERS_OFFSET + AMMO_OFFSET, y_pos, NUMBERS_WIDTH, NUMBERS_HEIGHT};
      renderer.render(numbers.getTexture(), &clip, &quad);
      ammo_quad = {AMMO_OFFSET + (i+2)*NUMBERS_OFFSET + (i+1)*NUMBERS_WIDTH, y_pos, NUMBERS_WIDTH, NUMBERS_HEIGHT};
    }
  }


  offset = AMMO_POSITION*NUMBERS_WIDTH + AMMO_POSITION*NUMBERS_OFFSET;
  clip = {offset, 0, NUMBERS_WIDTH, NUMBERS_HEIGHT};
  renderer.render(numbers.getTexture(), &clip, &ammo_quad);



}

void Hud::renderBomb(){
  if(!has_bomb){
    return;
  }

  SDL_Rect quad = {10, 10, 70, 64};
  renderer.render(hud_symbols.getTexture(), &clips[3], &quad);

}

void Hud::renderWeapon(){

  SDL_Rect quad = {window_width - 50, 10, weapons.at(weapon_type).get_w(), weapons.at(weapon_type).get_h()};
  renderer.render(weapons.at(weapon_type).getTexture(), NULL, &quad);
}

#include <iostream>

void Hud::renderTimeToExplode(){
  /*El total va a tener 214 de ancho y 66 de alto*/
  if(time_to_explode == NO_TIME){
    return;
  }

  int mins = time_to_explode/60.0;
  int secs = (time_to_explode/60.0 - mins)*60;
  int y_pos = 10;
  int offset = 0;
  int i = 0;

  std::string mins_str = std::to_string(mins);
  std::string secs_str = std::to_string(secs);
  SDL_Rect clip = {0};


  /*rederizo el reloj*/
  SDL_Rect quad = {CLOCK_POSITION, y_pos, SYMBOL_WIDTH, SYMBOL_HEIGHT};
  renderer.render(hud_symbols.getTexture(), &clips[4], &quad);

  /*rederizo los minutos*/
  for (i = 0; i < (int)mins_str.length(); i++) {
    offset = numbers_offset(mins_str, i);
    clip = {offset, 0, NUMBERS_WIDTH, NUMBERS_HEIGHT};
    quad = {i*NUMBERS_WIDTH + NUMBERS_OFFSET + SYMBOL_WIDTH + CLOCK_POSITION, y_pos, NUMBERS_WIDTH, NUMBERS_HEIGHT};
    renderer.render(numbers.getTexture(), &clip, &quad);
  }

  /*Renderizo los dos puntos*/
  int x_pos = i*NUMBERS_WIDTH + NUMBERS_OFFSET + SYMBOL_WIDTH + CLOCK_POSITION;
  quad = {x_pos, y_pos, COLON_WIDTH, NUMBERS_HEIGHT};
  renderer.render(numbers.getTexture(), &clips[5], &quad);

  /*rederizo los segundos*/
  x_pos = x_pos + COLON_WIDTH;

  for (i = 0; i < (int)secs_str.length(); i++) {
    x_pos = x_pos + i*NUMBERS_WIDTH + NUMBERS_OFFSET;
    offset = numbers_offset(secs_str, i);
    clip = {offset, 0, NUMBERS_WIDTH, NUMBERS_HEIGHT};
    quad = {x_pos, y_pos, NUMBERS_WIDTH, NUMBERS_HEIGHT};
    renderer.render(numbers.getTexture(), &clip, &quad);
  }
}

void Hud::render(){
  renderLife();
  renderMoney();
  renderAmmo();
  renderBomb();
  renderWeapon();
  renderTimeToExplode();
}


Hud::~Hud(){}
