#include "Stencil.h"


Stencil::Stencil(){}

void Stencil::buildStencil(Renderer& renderer, Texture& texture, double angle, int alpha){

    SDL_Texture* stencil = SDL_CreateTexture(renderer.getRenderer(), SDL_PIXELFORMAT_UNKNOWN,
                                              SDL_TEXTUREACCESS_TARGET, 800, 800);
    SDL_SetRenderTarget(renderer.getRenderer(), stencil);

    SDL_Rect fillRect = { 0, 0, 800, 800};
    SDL_SetRenderDrawColor( renderer.getRenderer(), 0x00, 0x00, 0x00, 0x00 );
    SDL_RenderFillRect( renderer.getRenderer(), &fillRect );

    filledCircleColor(renderer.getRenderer(), 400, 400, 30, 0xFFFFFFFF);

    double altura = tan(angle*PI/360)*400; //DIVIDO POR 180*2
    filledTrigonColor(renderer.getRenderer(), 400, 400, 800, 400-altura, 800, 400+altura, 0xFFFFFFFF);

    SDL_Surface* surface = SDL_CreateRGBSurface(0, 800, 800, 32, 0, 0, 0, 0);
    SDL_RenderReadPixels(renderer.getRenderer(), NULL, surface->format->format, surface->pixels, surface->pitch);

    Color key = {0xFF,0xFF,0xFF};
    texture.loadFromSurface(renderer, surface, key, SDL_BLENDMODE_BLEND, alpha);

    SDL_FreeSurface(surface);
    SDL_SetRenderTarget(renderer.getRenderer(), NULL);
}

Stencil::~Stencil(){}
