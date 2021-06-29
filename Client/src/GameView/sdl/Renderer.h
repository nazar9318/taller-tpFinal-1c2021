#ifndef __RENDERER_H__
#define __RENDERER_H__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Window.h"
// #include "Texture.h"
#include "SDLException.h"

// #include <iostream>

class Renderer {

  private:
    bool initialized = false;
    Window& window;
    SDL_Renderer* renderer = NULL;

  public:
    /**
     * Ctor standalone
     */
    Renderer(Window& window);

    void clearScreen() const;

    void presentScreen() const;

    // void render(SDL_Texture* texture, SDL_Rect* src, SDL_Rect* dest);

    // void render(SDL_Texture* texture, SDL_Rect* src, SDL_Rect* dest, double angle);

    void render(SDL_Texture* texture, SDL_Rect* src, SDL_Rect* dest, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );

    // Renders texture at given point
		// void render(SDL_Texture* texture, int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );

    SDL_Texture* createTextureFromSurface(SDL_Surface* surface) const;

    void setDrawColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

    SDL_Renderer* getRenderer();

    ~Renderer();

  private:

    void setDrawColor() const;

};

#endif
