#ifndef __STENCIL_H__
#define __STENCIL_H__

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <math.h>
#include "Texture.h"
#include "Renderer.h"

#define PI 3.14159265

class Stencil {
  public:

    Stencil();

    static void buildStencil(Renderer& renderer, Texture& texture, double angle, int alpha, int radius);

    ~Stencil();


};

#endif
