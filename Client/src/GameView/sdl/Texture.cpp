#include "Texture.h"

Texture::Texture(){}


SDL_Texture* Texture::getTexture() const {
  if (!texture) {
    throw SDLException("SDLException: Texture is NULL - %s\n", SDL_GetError());
  }
  return texture;
}

void Texture::loadFromFile(const Renderer& renderer, std::string filePath){
  SDL_Surface *tmp = IMG_Load(filePath.c_str());
  if (!tmp) {
    throw SDLException("SDLException: failed to load surface - %s\n", SDL_GetError());
  }

  texture = renderer.createTextureFromSurface(tmp);
  if (!texture) {
    SDL_FreeSurface(tmp);
    throw SDLException("SDLException: failed to create texture - %s\n", SDL_GetError());
  }

  this->height = tmp->h;
  this->width = tmp->w;

  /* releases the temporary surface */
  SDL_FreeSurface(tmp);

}

void Texture::loadFromFile(const Renderer& renderer, std::string filePath, Color key){
  SDL_Surface *tmp = IMG_Load(filePath.c_str());
  if (!tmp) {
    throw SDLException("SDLException: failed to load surface - %s\n", SDL_GetError());
  }

  SDL_SetColorKey(tmp, SDL_TRUE, SDL_MapRGB(tmp->format, key.r, key.g, key.b));

  texture = renderer.createTextureFromSurface(tmp);
  if (!texture) {
    SDL_FreeSurface(tmp);
    throw SDLException("SDLException: failed to create texture - %s\n", SDL_GetError());
  }

  this->height = tmp->h;
  this->width = tmp->w;

  /* releases the temporary surface */
  SDL_FreeSurface(tmp);

}

void Texture::loadFromFile(const Renderer& renderer, std::string filePath, Color key, SDL_BlendMode blending, uint8_t alpha){
  loadFromFile(renderer, filePath, key);
  SDL_SetTextureBlendMode(this->texture, blending);
  SDL_SetTextureAlphaMod(this->texture, alpha);
}

void Texture::free() {
  if (texture) {
    SDL_DestroyTexture(texture);
    texture = NULL;
    width = 0;
    height = 0;
  }
}

int Texture::get_w(){
  return width;
}

int Texture::get_h(){
  return height;
}

Texture::~Texture() {
    free();
}
