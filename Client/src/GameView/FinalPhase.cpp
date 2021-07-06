#include "FinalPhase.h"
#include <iostream>

FinalPhase::FinalPhase(Renderer& renderer, int screen_width, int screen_height):
renderer(renderer), screen_width(screen_width), screen_height(screen_height) {
  names.push_back("Nombre");
  round_kills.push_back("Puntos ronda");
  total_kills.push_back("Puntos totales");
}

void FinalPhase::loadMedia() {
  font = TTF_OpenFont("../Client/Assets/Fonts/japanese.ttf", 20);
  if (!font){
    throw SDLException("SDLException: failed to load fonts -> FinalPhase - %s\n",TTF_GetError());
  }
}

void FinalPhase::addScore(const std::string& name, int round_kills, int total_kills) {
  std::stringstream round;
  std::stringstream total;
  round << round_kills;
  total << total_kills;
  this->names.push_back(name);
  this->round_kills.push_back(round.str());
  this->total_kills.push_back(total.str());
}

void FinalPhase::render() {
  SDL_Color white = {255, 255, 255};

  SDL_Rect quad_name = {
    screen_width/2 - 300,
    0,
    80,
    40
  };
  for (unsigned int i = 0; i < names.size(); i++) {
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, names[i].c_str(), white);
    SDL_Texture* Message = renderer.createTextureFromSurface(surfaceMessage);
    renderer.render(Message, NULL, &quad_name);
    quad_name.y += 40;
  }

  SDL_Rect quad_round = {
    screen_width/2 - 150,
    0,
    80,
    40
  };
  for (unsigned int i = 0; i < round_kills.size(); i++) {
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, round_kills[i].c_str(), white);
    SDL_Texture* Message = renderer.createTextureFromSurface(surfaceMessage);
    renderer.render(Message, NULL, &quad_round);
    quad_round.y += 40;
  }

  SDL_Rect quad_total = {
    screen_width/2,
    0,
    80,
    40
  };
  for (unsigned int i = 0; i < total_kills.size(); i++) {
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, total_kills[i].c_str(), white);
    SDL_Texture* Message = renderer.createTextureFromSurface(surfaceMessage);
    renderer.render(Message, NULL, &quad_total);
    quad_total.y += 40;
  }
}

FinalPhase::~FinalPhase() {}
