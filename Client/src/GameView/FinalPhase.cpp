#include "FinalPhase.h"
#include <iostream>

FinalPhase::FinalPhase(Renderer& renderer, int screen_width, int screen_height):
renderer(renderer), screen_width(screen_width), screen_height(screen_height), font(NULL) {
  names.push_back("Nombre");
  round_kills.push_back("Puntos ronda");
  total_kills.push_back("Puntos totales");
}

void FinalPhase::loadMedia() {
  font = TTF_OpenFont("../Client/Assets/Fonts/japanese.ttf", 20);
  if (!font) {
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
  SDL_Rect quad_name = {0};
  quad_name.x = screen_width/2 - 400;
  quad_name.y = 0;
  quad_name.h = 40;
  for (unsigned int i = 0; i < names.size(); i++) {
    quad_name.w = 15*names[i].size();
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, names[i].c_str(), white);
    SDL_Texture* Message = renderer.createTextureFromSurface(surfaceMessage);
    renderer.render(Message, NULL, &quad_name);
    quad_name.y += 40;
    SDL_FreeSurface(surfaceMessage);
  }
  SDL_Rect quad_round = {0};
  quad_round.x = screen_width/2 - 100;
  quad_round.y = 0;
  quad_round.h = 40;
  for (unsigned int i = 0; i < round_kills.size(); i++) {
    quad_round.w = 15*round_kills[i].size();
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, round_kills[i].c_str(), white);
    SDL_Texture* Message = renderer.createTextureFromSurface(surfaceMessage);
    renderer.render(Message, NULL, &quad_round);
    quad_round.y += 40;
    SDL_FreeSurface(surfaceMessage);
  }
  SDL_Rect quad_total = {0};
  quad_total.x = screen_width/2 + 150;
  quad_total.y = 0;
  quad_total.h = 40;
  for (unsigned int i = 0; i < total_kills.size(); i++) {
    quad_total.w = 15*total_kills[i].size();
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, total_kills[i].c_str(), white);
    SDL_Texture* Message = renderer.createTextureFromSurface(surfaceMessage);
    renderer.render(Message, NULL, &quad_total);
    quad_total.y += 40;
    SDL_FreeSurface(surfaceMessage);
  }
  this->names.clear();
  this->round_kills.clear();
  this->total_kills.clear();
  names.push_back("Nombre");
  round_kills.push_back("Puntos ronda");
  total_kills.push_back("Puntos totales");
}

FinalPhase::~FinalPhase() {
  if (font != NULL) { TTF_CloseFont(font); }
}
