#include "Renderer.h"


Renderer::Renderer(Window& window):window(window){
  renderer = SDL_CreateRenderer(window.getWindow(), -1, SDL_RENDERER_ACCELERATED);
  if (renderer == NULL) {
    throw SDLException("Error in function SDL_CreateRenderer()\nSDL_Error: %s", SDL_GetError());
  }

  if (SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND)) {
    throw SDLException("Error in function SDL_SetRenderDrawBlendMode()\nSDL_Error: %s", SDL_GetError());
  }

  setDrawColor();
}

void Renderer::setDrawColor() const{
  if (SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF )) {
    throw SDLException("SDLException: failed to set drawing color - %s\n",
    SDL_GetError());
  }
}

void Renderer::setDrawColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
  if (SDL_SetRenderDrawColor(renderer, r, g, b, a) != 0) {
    throw SDLException("SDLException: failed to set drawing color - %s\n",SDL_GetError());
  }
}

SDL_Texture* Renderer::createTextureFromSurface(SDL_Surface* surface) const{
  SDL_Texture* new_texture =  SDL_CreateTextureFromSurface(renderer, surface);
  if (!new_texture) {
    throw SDLException("SDLException: failed to create texture from surface - %s\n",SDL_GetError());
  }
  return new_texture;
}


void Renderer::render(SDL_Texture* texture, SDL_Rect* src, SDL_Rect* dest){
  SDL_RenderCopy( renderer, texture, src, dest);
}

void Renderer::render(SDL_Texture* texture, SDL_Rect* src, SDL_Rect* dest, double angle){
  SDL_RendererFlip flip = SDL_FLIP_NONE;
  SDL_RenderCopyEx( renderer, texture, src, dest, angle, NULL, flip);
}

void Renderer::clearScreen() const{
  if (SDL_RenderClear(renderer)) {
    throw SDLException("SDLException: failed to clear screen - %s\n",SDL_GetError());
  }
}

void Renderer::presentScreen() const{
  SDL_RenderPresent(renderer);
}

SDL_Renderer* Renderer::getRenderer(){
  return renderer;
}

Renderer::~Renderer() {
    if (renderer) {
        SDL_DestroyRenderer(renderer);
        renderer = NULL;
    }
}
