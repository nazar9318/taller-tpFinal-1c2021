#include "Camera.h"

Camera::Camera(Renderer& renderer, int screen_width, int screen_height) :
renderer(renderer) {
  box.x = 0;
  box.y = 0;
  box.w = screen_width;
  box.h = screen_height;  //Esto sale del cfg file
}


void Camera::render(Texture& texture, int x, int y, int w, int h) {
  SDL_Rect renderQuad = { x, y, texture.get_w(), texture.get_h() };
  // renderQuad.w = box.w;
  // renderQuad.h = box.h;
  renderer.render(texture.getTexture(), NULL, &renderQuad);
  // renderer.render(texture.getTexture(), &box, &renderQuad);
}

void Camera::center(SDL_Rect& object, int map_width, int map_height) {
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

bool Camera::isVisible(SDL_Rect& object){
  if ((object.y + object.h) <= pos.y || object.y >= (pos.y + box.h) ||
      (object.x + object.w) <= pos.x || object.x >= (pos.x + box.w)) {
      return false;
  }

  return true;
}

int Camera::get_x() { return box.x; }

int Camera::get_y() { return box.y; }

Camera::~Camera() {}
