#include "InitialFase.h"

InitialFase::InitialFase(Renderer& renderer, int screen_width, int screen_height):
renderer(renderer), screen_width(screen_width), screen_height(screen_height), font(NULL) {}

void InitialFase::loadMedia(){
  background.loadFromFile(renderer, "../Client/Assets/InitialFase/background.png");

  /* Ak47 BUTTON*/
  ak.base.loadFromFile(renderer, "../Client/Assets/InitialFase/button.png");
  ak.pressed.loadFromFile(renderer, "../Client/Assets/InitialFase/selected_button.png");

  /* AWP BUTTON*/


  /* M3 BUTTON*/


  /*FONT*/
  font = TTF_OpenFont("../Client/Assets/Fonts/japanese.ttf", 5);
  if (!font) {
    throw SDLException("SDLException: failed to load fonts -> InitialFase - %s\n",TTF_GetError());
  }
}

// void InitialFase::run(){
//   SDL_Event e;
//   while(/**/){
//     while( SDL_PollEvent( &e ) != 0 ){
//       if(e.type == SDL_MOUSEBUTTONDOWN){
//         handle_click();
//       }
//     }
//   }
// }

void InitialFase::render() {
  SDL_Rect quad = {screen_width/2 - 225, screen_height/2 - 225, background.get_w(), background.get_h()};
  renderer.render(background.getTexture(), NULL, &quad);

  ak.render_box = {quad.x + 50, quad.y + 50, ak.base.get_w(), ak.base.get_h()};
  if(ak.mouse_over){
    renderer.render(ak.pressed.getTexture(), NULL, &ak.render_box);
  } else{
    renderer.render(ak.base.getTexture(), NULL, &ak.render_box);
  }
}

InitialFase::~InitialFase() {
  if (font != NULL) { TTF_CloseFont(font); }
}
