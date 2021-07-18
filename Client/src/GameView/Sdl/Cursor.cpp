#include "Cursor.h"

Cursor::Cursor():img(NULL), cursor(NULL){

}

void Cursor::setCrusor(std::string path, uint8_t r_key, uint8_t g_key, uint8_t b_key){
  img = IMG_Load(path.c_str());
  if(!img){
    throw SDLException("SDLException: failed to load cursor surface\n");
  }

  SDL_SetColorKey(img, SDL_TRUE, SDL_MapRGB(img->format, r_key, g_key, b_key));

  cursor = SDL_CreateColorCursor(img, 0, 0);
  if(!cursor){
    throw SDLException("SDLException: failed to create cursor\n");
  }

  SDL_SetCursor(cursor);
}

Cursor::~Cursor(){
  SDL_FreeCursor(cursor);
  SDL_FreeSurface(img);
}
