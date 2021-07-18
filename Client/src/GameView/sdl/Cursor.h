#ifndef __CURSOR_H__
#define __CURSOR_H__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "SDLException.h"
#include <string>

class Cursor {
  private:
    SDL_Surface* img;
    SDL_Cursor* cursor;

  public:
    Cursor();

    void setCrusor(std::string path, uint8_t r_key, uint8_t g_key, uint8_t b_key);

    ~Cursor();

};

#endif
