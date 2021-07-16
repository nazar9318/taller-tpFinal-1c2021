#include "InitialPhase.h"

#define BUTTON_WIDTH 360
#define BUTTON_HEIGHT 40
#define BUTTON_X_OFFSET 45
#define BUTTON_Y_OFFSET 20
#define NAME_X_OFFSET 10
#define NAME_Y_OFFSET 10
#define PRICE_X_OFFSET 10
#define PRICE_Y_OFFSET 10
#define BACKGROUND_WIDTH 450
#define BACKGROUND_HEIGHT 450

InitialPhase::InitialPhase(Renderer& renderer, int screen_width, int screen_height,
                            ProtectedQueue<std::unique_ptr<Event>>& client):
  renderer(renderer),
  screen_width(screen_width),
  screen_height(screen_height),
  font(NULL),
  client_event(client),
  number_of_weapons(2),
  ticks_rendered(0),
  successful_buy(true){}

void InitialPhase::loadMedia(){

  SDL_Color white = {255, 255, 255};

  /*FONT*/
  font = TTF_OpenFont("../Client/Assets/Fonts/japanese.ttf", 20);
  if (!font) {
    throw SDLException("SDLException: failed to load fonts -> InitialPhase - %s\n",TTF_GetError());
  }

  /*BUTTONS*/
  background.loadFromFile(renderer, "../Client/Assets/InitialPhase/background.png");
  button.loadFromFile(renderer, "../Client/Assets/InitialPhase/button.png");
  button_over.loadFromFile(renderer, "../Client/Assets/InitialPhase/over_button.png");
  button_pressed.loadFromFile(renderer, "../Client/Assets/InitialPhase/pressed_button.png");

  /*BUTTONS TEXT*/
  buttons[PositionType::AK47].text.loadFromRenderedText(renderer, font, "AK-47", white, SOLID_TEXT);
  buttons[PositionType::AWP].text.loadFromRenderedText(renderer, font, "AWP", white, SOLID_TEXT);
  buttons[PositionType::M3].text.loadFromRenderedText(renderer, font, "M3", white, SOLID_TEXT);
  buttons[PositionType::PRIMARY_AMMO].text.loadFromRenderedText(renderer, font, "PRIMARY AMMO", white, SOLID_TEXT);
  buttons[PositionType::SECONDARY_AMMO].text.loadFromRenderedText(renderer, font, "SECONDARY AMMO", white, SOLID_TEXT);


  for (auto it = buttons.begin(); it != buttons.end(); ++it) {
    it->second.base = &button;
    it->second.over = &button_over;
    it->second.pressed = &button_pressed;
  }

}

bool InitialPhase::inside(SDL_Point& pos, SDL_Rect& box){
    if ((pos.x > (box.x + box.w)) || (pos.x < (box.x)) ||
        (pos.y > (box.y + box.h)) || (pos.y < (box.y))) {
        return false;
    }
    return true;
}

void InitialPhase::handleButton(SDL_Event& event, PositionType weapon_button){

  switch (event.type) {
    case SDL_MOUSEBUTTONDOWN:
      if(event.button.button == SDL_BUTTON_LEFT){
        buttons[weapon_button].mouse_pressed = true;
        buttons[weapon_button].mouse_over = false;

        if(weapon_button == PositionType::PRIMARY_AMMO || weapon_button == PositionType::SECONDARY_AMMO){
          std::unique_ptr<Event> bullet_type(new BuyBulletsEvent((char)weapon_button));
          this->client_event.push(bullet_type);
        } else {
          std::unique_ptr<Event> weapon_type(new BuyWeaponEvent((char)weapon_button));
          this->client_event.push(weapon_type);
        }
      }
      break;
    case SDL_MOUSEBUTTONUP:
      if(event.button.button == SDL_BUTTON_LEFT){
        buttons[weapon_button].mouse_pressed = false;
      }
      break;

    default:
      break;
  }
}

void InitialPhase::handleEvents(SDL_Event& event, SDL_Point& mousePosition){

  for (auto it = buttons.begin(); it != buttons.end(); ++it) {
    if(inside(mousePosition, it->second.render_box)){
      if(number_of_weapons == 2 && it->first == PositionType::SECONDARY_AMMO){

      } else {
        it->second.mouse_over = true;
        handleButton(event, (PositionType)it->first);
      }
    } else {
      it->second.mouse_over = false;
    }
  }
}

bool InitialPhase::run(){
  SDL_Event event;

  while(SDL_PollEvent(&event)){

    if(event.type == SDL_MOUSEMOTION || event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_MOUSEBUTTONUP){

      int mouse_x, mouse_y;
      SDL_GetMouseState(&mouse_x, &mouse_y);
      SDL_Point mousePosition = {mouse_x, mouse_y};

      handleEvents(event, mousePosition);
    }

    if(event.type == SDL_QUIT){
      return false;
    }
  }
  return true;
}

void InitialPhase::addPrice(int price, PositionType weapon){
  std::string price_str = std::to_string(price);
  price_str = "$" + price_str;

  SDL_Color white = {255, 255, 255};
  buttons[weapon].description.loadFromRenderedText(renderer, font, price_str, white, SOLID_TEXT);
}

void InitialPhase::updateMoney(int money){
  std::string money_str = std::to_string(money);
  money_str = "$" + money_str;
  SDL_Color white = {255, 255, 255};
  actual_money.loadFromRenderedText(renderer, font, money_str, white, SOLID_TEXT);
}

void InitialPhase::handleError(BuyState buy_state) {
  successful_buy = false;

  SDL_Color white = {255, 255, 255};
  error_msg.loadFromRenderedText(renderer, font, "Aca va el error", white, SOLID_TEXT);
}

void InitialPhase::updateValues(int money, BuyState buy_state, int number_of_weapons, int price_secconadary_ammo){
  updateMoney(money);
  if(buy_state != BuyState::SUCCESSFUL){
    handleError(buy_state);
  }
  this->number_of_weapons = number_of_weapons;
  addPrice(price_secconadary_ammo, PositionType::SECONDARY_AMMO);
}

void InitialPhase::renderErrorMessage(){
  if(ticks_rendered >= 30){
    ticks_rendered = 0;
    successful_buy = true;
    return;
  }

  /*renderizo el error 545454*/
  SDL_Rect quad = {screen_width/2 - BUTTON_WIDTH/2, screen_height/2 - BUTTON_HEIGHT/2, BUTTON_WIDTH, BUTTON_HEIGHT};
  renderer.render(button_over.getTexture(), NULL, &quad);

  SDL_Rect error_quad = {quad.x + BUTTON_WIDTH/2 - error_msg.get_w()/2,
                        quad.y + NAME_Y_OFFSET,
                        error_msg.get_w(), error_msg.get_h()};
  renderer.render(error_msg.getTexture(), NULL, &error_quad);
  ticks_rendered++;
}

void InitialPhase::renderBuysWindow(){
  SDL_Rect name_quad = {0};
  SDL_Rect price_quad = {0};
  int y = 0;

  SDL_Rect quad = {screen_width/2 - BACKGROUND_WIDTH/2, screen_height/2 - BACKGROUND_HEIGHT/2, BACKGROUND_WIDTH, BACKGROUND_HEIGHT};
  renderer.render(background.getTexture(), NULL, &quad);

  y = quad.y + 10;

  for (auto it = buttons.begin(); it != buttons.end(); ++it) {
    it->second.render_box = {quad.x + BUTTON_X_OFFSET, y + BUTTON_HEIGHT + BUTTON_Y_OFFSET, BUTTON_WIDTH, BUTTON_HEIGHT};
    y = y + BUTTON_HEIGHT + BUTTON_Y_OFFSET;

    if(it->second.mouse_over){
      renderer.render(it->second.over->getTexture(), NULL, &it->second.render_box);
    } else if(it->second.mouse_pressed){
      renderer.render(it->second.pressed->getTexture(), NULL, &it->second.render_box);
    } else {
      renderer.render(it->second.base->getTexture(), NULL, &it->second.render_box);
    }


    name_quad = {it->second.render_box.x + NAME_X_OFFSET, it->second.render_box.y + NAME_Y_OFFSET, it->second.text.get_w(), it->second.text.get_h()};
    renderer.render(it->second.text.getTexture(), NULL, &name_quad);

    if(it->first == PositionType::SECONDARY_AMMO && number_of_weapons == 2){

    } else {
      price_quad = {it->second.render_box.x + BUTTON_WIDTH - NAME_X_OFFSET - it->second.description.get_w(), it->second.render_box.y + NAME_Y_OFFSET,
        it->second.description.get_w(), it->second.description.get_h()};
      renderer.render(it->second.description.getTexture(), NULL, &price_quad);
    }
    }

    SDL_Rect money_quad = {quad.x + BACKGROUND_WIDTH/2 - actual_money.get_w()/2, quad.y + BACKGROUND_HEIGHT - 50,
                           actual_money.get_w(), actual_money.get_h()};
    renderer.render(actual_money.getTexture(), NULL, &money_quad);
}


void InitialPhase::render() {
  if(successful_buy){
    renderBuysWindow();
  }else{
    renderErrorMessage();
  }
}

InitialPhase::~InitialPhase() {
  if (font != NULL) { TTF_CloseFont(font); }
}
