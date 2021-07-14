#include "InitialPhase.h"
#include <iostream>
InitialPhase::InitialPhase(Renderer& renderer, int screen_width, int screen_height):
  renderer(renderer),
  screen_width(screen_width),
  screen_height(screen_height),
  font(NULL){}

void InitialPhase::loadMedia(){

  SDL_Color white = {255, 255, 255};

  /*FONT*/
  font = TTF_OpenFont("../Client/Assets/Fonts/japanese.ttf", 20);
  if (!font) {
    throw SDLException("SDLException: failed to load fonts -> InitialPhase - %s\n",TTF_GetError());
  }

  background.loadFromFile(renderer, "../Client/Assets/InitialPhase/background.png");
  button.loadFromFile(renderer, "../Client/Assets/InitialPhase/button.png");
  button_over.loadFromFile(renderer, "../Client/Assets/InitialPhase/over_button.png");
  button_pressed.loadFromFile(renderer, "../Client/Assets/InitialPhase/pressed_button.png");

  /* Ak47 BUTTON*/
  ak47.base = &button;
  ak47.over = &button_over;
  ak47.pressed = &button_pressed;
  // ak47.base.loadFromFile(renderer, "../Client/Assets/InitialPhase/button.png");
  // ak47.over.loadFromFile(renderer, "../Client/Assets/InitialPhase/over_button.png");
  // ak47.pressed.loadFromFile(renderer, "../Client/Assets/InitialPhase/pressed_button.png");
  ak47.text.loadFromRenderedText(renderer, font, "AK-47", white, SOLID_TEXT);

  // /* AWP BUTTON*/
  // awp.base.loadFromFile(renderer, "../Client/Assets/InitialPhase/button.png");
  // awp.over.loadFromFile(renderer, "../Client/Assets/InitialPhase/over_button.png");
  // awp.pressed.loadFromFile(renderer, "../Client/Assets/InitialPhase/pressed_button.png");
  // awp.text.loadFromRenderedText(renderer, font, "AWP", white, SOLID_TEXT);
  //
  //
  // /* M3 BUTTON*/
  // m3.base.loadFromFile(renderer, "../Client/Assets/InitialPhase/button.png");
  // m3.over.loadFromFile(renderer, "../Client/Assets/InitialPhase/over_button.png");
  // m3.pressed.loadFromFile(renderer, "../Client/Assets/InitialPhase/pressed_button.png");
  // m3.text.loadFromRenderedText(renderer, font, "M3", white, SOLID_TEXT);
  //
  // /* PRIMARY_AMMO BUTTON*/
  // primary_ammo.base.loadFromFile(renderer, "../Client/Assets/InitialPhase/button.png");
  // primary_ammo.over.loadFromFile(renderer, "../Client/Assets/InitialPhase/over_button.png");
  // primary_ammo.pressed.loadFromFile(renderer, "../Client/Assets/InitialPhase/pressed_button.png");
  // primary_ammo.text.loadFromRenderedText(renderer, font, "PRIMARY AMMO", white, SOLID_TEXT);
  //
  // /* SECONDARY_AMMO BUTTON*/
  // secondary_ammo.base.loadFromFile(renderer, "../Client/Assets/InitialPhase/button.png");
  // secondary_ammo.over.loadFromFile(renderer, "../Client/Assets/InitialPhase/over_button.png");
  // secondary_ammo.pressed.loadFromFile(renderer, "../Client/Assets/InitialPhase/pressed_button.png");
  // secondary_ammo.text.loadFromRenderedText(renderer, font, "SECONDARY AMMO", white, SOLID_TEXT);


}

bool InitialPhase::inside(SDL_Point& pos, SDL_Rect& box){
    if ((pos.x > (box.x + box.w)) || (pos.x < (box.x)) ||
        (pos.y > (box.y + box.h)) || (pos.y < (box.y))) {
        return false;
    }

    return true;
}

void InitialPhase::handleAk47(SDL_Event& event){

    switch (event.type) {
      case SDL_MOUSEBUTTONDOWN:
        if(event.button.button == SDL_BUTTON_LEFT){
          std::cout << "Comprando ak47" << '\n';
          ak47.mouse_pressed = true;
        }
        break;
      case SDL_MOUSEBUTTONUP:
        if(event.button.button == SDL_BUTTON_LEFT){
          ak47.mouse_pressed = false;
        }
        break;
    }
}

void InitialPhase::handleEvents(SDL_Event& event, SDL_Point& mousePosition){

  if(inside(mousePosition, ak47.render_box)){
    ak47.mouse_over = true;
    handleAk47(event);
  } else {
    ak47.mouse_over = false;
  }
  //
  // if(inside(mousePosition, ak47.render_box)){
  //   ak47.mouse_over = true;
  //   handleAk47(event);
  // } else {
  //   ak47.mouse_over = false;
  // }
  //
  // if(inside(mousePosition, ak47.render_box)){
  //   ak47.mouse_over = true;
  //   handleAk47(event);
  // } else {
  //   ak47.mouse_over = false;
  // }
  //
  // if(inside(mousePosition, ak47.render_box)){
  //   ak47.mouse_over = true;
  //   handleAk47(event);
  // } else {
  //   ak47.mouse_over = false;
  // }
  //
  // if(inside(mousePosition, ak47.render_box)){
  //   ak47.mouse_over = true;
  //   handleAk47(event);
  // } else {
  //   ak47.mouse_over = false;
  // }

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

void InitialPhase::render() {

  SDL_Rect text_quad = {0};

  SDL_Rect quad = {screen_width/2 - 225, screen_height/2 - 225, background.get_w(), background.get_h()};
  renderer.render(background.getTexture(), NULL, &quad);


  ak47.render_box = {quad.x + 45, quad.y + 70, ak47.base->get_w(), ak47.base->get_h()};

  if(ak47.mouse_over){
    renderer.render(ak47.over->getTexture(), NULL, &ak47.render_box);
  } else if(ak47.mouse_pressed){
    renderer.render(ak47.pressed->getTexture(), NULL, &ak47.render_box);
  } else {
    renderer.render(ak47.base->getTexture(), NULL, &ak47.render_box);
  }

  text_quad = {ak47.render_box.x + 10, ak47.render_box.y + 10, ak47.text.get_w(), ak47.text.get_h()};
  renderer.render(ak47.text.getTexture(), NULL, &text_quad);
}

InitialPhase::~InitialPhase() {
  if (font != NULL) { TTF_CloseFont(font); }
}
