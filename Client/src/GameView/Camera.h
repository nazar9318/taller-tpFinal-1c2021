#ifndef __CAMERA_H__
#define __CAMERA_H__

#include <SDL2/SDL.h>
#include "Renderer.h"
#include "Texture.h"

class Camera {

  private:
    SDL_Rect box = {0};
    SDL_Point pos = {0};
    Renderer& renderer;


  public:
    Camera(Renderer& renderer, int map_width, int map_height);

    /* Obtiene los extremos visibles */
    void getVisibleRect(int& x_min, int& x_max, int& y_min, int& y_max);

    /* Devuelve si el objeto es visible por la camara o no */
    bool isVisible(SDL_Rect& object);

    /* Renderiza una textura agregandole un offset, SEA O NO VISIBLE */
    void renderAddingOffset(SDL_Texture* texture, SDL_Rect& render_quad, SDL_Rect* clip = NULL, double angle = 0.0);

    /* Offset de la camara en X */
    int xOffset();

    /* Offset de la camara en Y */
    int yOffset();

    /* Centra la camara en torno al objeto */
    void center(SDL_Rect object,  int map_width,  int map_height);

    SDL_Point getPos();

    // void render(Texture& texture, int x, int y);
    // int get_x();
    // int get_y();

    ~Camera();

  private:
    Camera(const Camera &other) = delete;
    Camera& operator=(const Camera &other) = delete;

};

#endif
