#include "Stencil.h"

#define STENCIL_WIDTH 800
#define STENCIL_HEIGHT 800
#define STENCIL_CENTER_X 400
#define STENCIL_CENTER_Y 400

Stencil::Stencil(){}

void Stencil::buildStencil(Renderer& renderer, Texture& texture, double angle, int alpha, int radius){

    SDL_Texture* stencil = SDL_CreateTexture(renderer.getRenderer(), SDL_PIXELFORMAT_UNKNOWN,
                                              SDL_TEXTUREACCESS_TARGET, STENCIL_WIDTH, STENCIL_HEIGHT);
    SDL_SetRenderTarget(renderer.getRenderer(), stencil);

    SDL_Rect fillRect = { 0, 0, STENCIL_WIDTH, STENCIL_HEIGHT};
    SDL_SetRenderDrawColor( renderer.getRenderer(), 0x00, 0x00, 0x00, 0x00 );
    SDL_RenderFillRect( renderer.getRenderer(), &fillRect );

    filledCircleColor(renderer.getRenderer(), STENCIL_CENTER_X, STENCIL_CENTER_Y, radius, 0xFFFFFFFF);

    double altura = tan(angle*PI/360)*STENCIL_WIDTH/2; //DIVIDO POR 180*2 ya que es angle/2
    filledTrigonColor(renderer.getRenderer(), STENCIL_CENTER_X, STENCIL_CENTER_Y, STENCIL_WIDTH,
                      STENCIL_CENTER_Y-altura, STENCIL_HEIGHT, STENCIL_CENTER_Y+altura, 0xFFFFFFFF);

    SDL_Surface* surface = SDL_CreateRGBSurface(0, STENCIL_WIDTH, STENCIL_HEIGHT, 32, 0, 0, 0, 0);
    SDL_RenderReadPixels(renderer.getRenderer(), NULL, surface->format->format, surface->pixels, surface->pitch);

    Color key = {0xFF,0xFF,0xFF};
    texture.loadFromSurface(renderer, surface, key, SDL_BLENDMODE_BLEND, alpha);

    SDL_FreeSurface(surface);
    SDL_SetRenderTarget(renderer.getRenderer(), NULL);
}

Stencil::~Stencil(){}
