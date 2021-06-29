#include "Camera.h"

Camera::Camera(Renderer& renderer/*Tengo que recibir el archivo de configs*/):renderer(renderer){
  box.x = 0;
  box.y = 0;
  box.w = 640;
  box.h = 480;  //Esto sale del cfg file

}

void Camera::render(Texture& texture, int x, int y){
  SDL_Rect renderQuad = { x, y, texture.get_w(), texture.get_h() };
  renderQuad.w = box.w;
  renderQuad.h = box.h;
  renderer.render(texture.getTexture(), &box, &renderQuad);
  // SDL_RenderCopyEx( renderer.getRenderer(), texture.getTexture(), &box, &renderQuad, 0, NULL, SDL_FLIP_NONE );
}

void Camera::center(SDL_Rect object, int map_width, int map_height){

  box.x = ( object.x + object.w / 2 ) - box.w / 2;
  box.y = ( object.y + object.h / 2 ) - box.h / 2;

  if( box.x < 0 ){
    box.x = 0;
  }
  if( box.y < 0 ){
    box.y = 0;
  }
  if( box.x > map_width - box.w ){
    box.x = map_width - box.w;
  }
  if( box.y > map_height - box.h ){
    box.y = map_height - box.h;
  }

}

int Camera::get_x(){
  return box.x;
}

int Camera::get_y(){
  return box.y;
}


Camera::~Camera(){}
