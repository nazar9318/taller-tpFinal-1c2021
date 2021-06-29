#ifndef __CAMERA_H__
#define __CAMERA_H__

#include <SDL2/SDL.h>
#include "Renderer.h"
#include "Texture.h"

class Camera {

  private:
    SDL_Rect box = {0};
    Renderer& renderer;

  public:
    Camera(Renderer& renderer);

    void center(SDL_Rect object, int map_width, int map_height);

    void render(Texture& texture, int x, int y);

    int get_x();
    int get_y();

    ~Camera();

  private:
    Camera(const Camera &other) = delete;
    Camera& operator=(const Camera &other) = delete;

};

#endif
