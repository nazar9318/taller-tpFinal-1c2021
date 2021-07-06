#include "Camera.h"

Camera::Camera(Renderer& renderer, int screen_width, int screen_height):renderer(renderer){
  box.x = 0;
  box.y = 0;
  box.w = screen_width;
  box.h = screen_height;

}

void Camera::getVisibleRect(int& x_min, int& x_max, int& y_min, int& y_max){
  x_min = pos.x;
  x_max = pos.x + box.w;
  y_min = pos.y;
  y_max = pos.y + box.h;
}

bool Camera::isVisible(SDL_Rect& object) {
    if ((object.y + object.h) <= pos.y || object.y >= (pos.y + box.h) ||
        (object.x + object.w) <= pos.x || object.x >= (pos.x + box.w)) {
        return false;
    }

    return true;
}

void Camera::render(SDL_Texture* texture, SDL_Rect& render_quad, SDL_Rect* clip, double angle){
  renderer.render(texture, clip, &render_quad, angle);
}

void Camera::renderAddingOffset(SDL_Texture* texture, SDL_Rect& render_quad, SDL_Rect* clip, double angle){
  render_quad.x -= pos.x;
  render_quad.y -= pos.y;

  renderer.render(texture, clip, &render_quad, angle);
}

int Camera::xOffset(){
    return pos.x;
}

int Camera::yOffset(){
    return pos.y;
}

SDL_Point Camera::getPos(){
  return pos;
}

void Camera::center(SDL_Rect object, int map_width, int map_height) {
    pos.x = (object.x + object.w / 2) - (box.w / 2);
    pos.y = (object.y + object.h / 2) - (box.h / 2);

    if (pos.x < 0) {
        pos.x = 0;
    }
    if (pos.y < 0) {
        pos.y = 0;
    }
    if (pos.x > map_width - box.w) {
        pos.x = map_width - box.w;
    }
    if (pos.y > map_height - box.h) {
        pos.y = map_height - box.h;
    }
}


Camera::~Camera(){}
