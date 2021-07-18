#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <string>
#include "SDLException.h"

class Window {

  private:
    int width;
    int height;
    SDL_Window* window;
    // SDL_Renderer* renderer; No se si lo necesito

  public:

    Window(const std::string& title, int w, int h, bool fullscreen);

    int clear();

    //Retorna un puntero al window
    SDL_Window* getWindow();

    ~Window();


};

#endif
