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

  window_icon = IMG_Load(WINDOW_ICON_PATH);
  if(!window){
    throw SDLException("SDLException: failed to laod Window Icon - %s\n",SDL_GetError());
  }

  SDL_SetWindowIcon(window, window_icon);

  this->fullscreen = fullscreen;
  if (fullscreen) {
    SDL_SetWindowFullscreen(window, SDL_TRUE);
  }
}

void Window::changeFullScreen(){
  if(fullscreen){
    SDL_SetWindowFullscreen(window, SDL_FALSE);
    fullscreen = false;
  } else {
    SDL_SetWindowFullscreen(window, SDL_TRUE);
    fullscreen = true;
  }
}

SDL_Window* Window::getWindow() { return window; }

Window::~Window(){
  if (window) {
    SDL_DestroyWindow(window);
    SDL_FreeSurface(window_icon);
    window = NULL;
  }
}
