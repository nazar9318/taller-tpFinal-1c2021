#include "Hud.h"


Hud::Hud(Renderer& renderer, int window_width, int window_height):renderer(renderer),
      window_width(window_width), window_height(window_height){}

void Hud::loadMedia(){
  Color black_color = {0x00, 0x00, 0x00};
  Color num_color = {0xFF, 0xFF, 0x00};
  Color money_color = {0xB8, 0xB2, 0x04};

  money_icon.loadFromFile(renderer, "../Client/Assets/Hud/money_icon.png", black_color, SDL_BLENDMODE_BLEND, 150);
  numbers.loadFromFile(renderer, "../Client/Assets/Hud/hud_nums.bmp", black_color, SDL_BLENDMODE_BLEND, 150);

  money_icon.setColor(money_color);
  numbers.setColor(num_color);
}

void Hud::update_values(char life, int money){
  this->life = (int)life;
  this->money = money;
}


int Hud::numbers_offset(std::string& string, int& i){
  int number = string[i] - 48;
  if(number != 0){
    return number*NUMBERS_WIDTH + number*NUMBERS_OFFSET;
  }
  return number*NUMBERS_WIDTH;
}

void Hud::render(){
  std::string life_str = std::to_string(life);
  std::string money_str = std::to_string(money);

  int offset = 0;
  int y_pos = window_height - NUMBERS_OFFSET - NUMBERS_HEIGHT;
  SDL_Rect clip = {0};
  SDL_Rect quad = {0};

  for (int i = 0; i < (int)life_str.length(); i++) {
    offset = numbers_offset(life_str, i);
    clip = {offset, 0, NUMBERS_WIDTH, NUMBERS_HEIGHT}; //Con esto obtengo el numero a renderizar
    quad = {i*NUMBERS_WIDTH + NUMBERS_OFFSET, y_pos, NUMBERS_WIDTH, NUMBERS_HEIGHT};
    renderer.render(numbers.getTexture(), &clip, &quad);
  }

  int money_offset = 1;

  for (int i = (int)money_str.length() - 1; i >= 0; i--) {
    offset = numbers_offset(money_str, i);
    clip = {offset, 0, NUMBERS_WIDTH, NUMBERS_HEIGHT}; //Con esto obtengo el numero a renderizar

    quad = {window_width - NUMBERS_OFFSET - (money_offset)*NUMBERS_WIDTH, y_pos, NUMBERS_WIDTH, NUMBERS_HEIGHT};
    renderer.render(numbers.getTexture(), &clip, &quad);
    money_offset++;
  }

  quad = {window_width + NUMBERS_OFFSET - (money_offset)*NUMBERS_WIDTH, y_pos, NUMBERS_WIDTH, NUMBERS_HEIGHT};
  renderer.render(money_icon.getTexture(), NULL, &quad);

}


Hud::~Hud(){}
