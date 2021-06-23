#ifndef __RENDERER_H__
#define __RENDERER_H__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Window.h"
#include "SDLException.h"


class Renderer {

  private:
    bool initialized = false;
    Window& window;
    SDL_Renderer* renderer = NULL;

  public:
    Renderer(Window& window);

    void clearScreen() const;

    void presentScreen() const;

    void render(SDL_Texture* texture, SDL_Rect* src, SDL_Rect* dest);

    void render(SDL_Texture* texture, SDL_Rect* src, SDL_Rect* dest, double angle);

    SDL_Texture* createTextureFromSurface(SDL_Surface* surface) const;

    void setDrawColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

    SDL_Renderer* getRenderer();

    ~Renderer();

  private:

    void setDrawColor() const;

};

#endif
