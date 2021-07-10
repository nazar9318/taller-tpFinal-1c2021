#include "Window.h"

Window::Window(const std::string& title, int w, int h, bool fullscreen):width(w), height(h){
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
    throw SDLException("SDLException: failed to initialize - %s\n", SDL_GetError());
  }

  if (TTF_Init() == -1) {
    throw SDLException("SDLException: failed to initialize - %s\n", SDL_GetError());
  }

  window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,width, height, SDL_WINDOW_SHOWN);
  if(!window){
    throw SDLException("SDLException: failed to create Window - %s\n",SDL_GetError());
  }
  SDL_SetWindowTitle(this->window, title.c_str());

  if (fullscreen) {
    SDL_SetWindowFullscreen(window, SDL_TRUE);
  }
}

// int Window::clear(){
//   if (renderer.clear() != 0) {
//     throw SDLException("SDLException: failed to clear renderer - %s\n", SDL_GetError());
//   }
// }

SDL_Window* Window::getWindow() { return window; }

Window::~Window(){
  if (window) {
    SDL_DestroyWindow(window);
    window = NULL;
  }
}
