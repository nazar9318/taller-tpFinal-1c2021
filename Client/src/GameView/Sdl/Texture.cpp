#include "Texture.h"

Texture::Texture():texture(NULL) {}

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

void Texture::loadFromSurface(Renderer& renderer, SDL_Surface* surface, Color key, SDL_BlendMode blending, uint8_t alpha){

  SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, key.r, key.g, key.b));

  texture = renderer.createTextureFromSurface(surface);
  if (!texture) {
    SDL_FreeSurface(surface);
    throw SDLException("SDLException: failed to create texture - %s\n", SDL_GetError());
  }

  this->height = surface->h;
  this->width = surface->w;

  SDL_SetTextureBlendMode(this->texture, blending);
  SDL_SetTextureAlphaMod(this->texture, alpha);
}

void Texture::loadFromRenderedText(Renderer& renderer, TTF_Font* font, std::string text, SDL_Color color, TextType type){
    // Eliminamos una textura previa si existe
    free();
    // Generamos la surface de texto
    SDL_Surface* text_surface = NULL;

    switch (type) {
        case SOLID_TEXT: {
            text_surface = TTF_RenderText_Solid(font, text.c_str(), color);
            break;
        }

        case BLENDED_TEXT: {
            text_surface = TTF_RenderText_Blended(font, text.c_str(), color);
            break;
        }

        default: {
            throw SDLException("SDLException: failed to create texture from text\n");
        }
    }

    if (text_surface == NULL) {
        throw SDLException("Error in function TTF_RenderUTF8 - SDL_Error: %s",SDL_GetError());
    }

    // Creamos la textura desde la surface
    texture = renderer.createTextureFromSurface(text_surface);
    if (!texture) {
      SDL_FreeSurface(text_surface);
      throw SDLException("SDLException: failed to create texture - %s\n", SDL_GetError());
    }

    // Seteamos las dimensiones
    this->height = text_surface->h;
    this->width = text_surface->w;

    // Liberamos la surface
    SDL_FreeSurface(text_surface);
}

void Texture::free() {
  if (texture) {
    SDL_DestroyTexture(texture);
    texture = NULL;
    width = 0;
    height = 0;
  }
}

int Texture::get_w() { return width; }

int Texture::get_h() { return height; }

void Texture::setColor(Color& color){
  SDL_SetTextureColorMod(texture, color.r, color.g, color.b);
}

Texture::~Texture() {
  free();
}
