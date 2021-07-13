#ifndef __BUTTON_H__
#define __BUTTON_H__


#include "Texture.h"
#include <SDL2/SDL.h>

struct Button {
    // Flag de animación
    bool mouse_over;
    bool mouse_pressed;

    // Offset de renderizado
    SDL_Rect render_box;

    // Texturas
    Texture base;
    Texture over;
    Texture pressed;
    Texture text;

    // Constructor por defecto
    Button() : mouse_over(false), mouse_pressed(false), render_box({0}) {}
};


#endif
