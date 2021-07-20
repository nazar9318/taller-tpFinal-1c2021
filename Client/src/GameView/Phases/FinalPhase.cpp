#include "FinalPhase.h"
#include <iostream>

FinalPhase::FinalPhase(Renderer& renderer, int screen_width, int screen_height):
renderer(renderer), screen_width(screen_width), screen_height(screen_height),
font(NULL), post_game(false), total_rounds(10) {}

void FinalPhase::loadMedia() {
  background_victory.loadFromFile(renderer, FINAL_PHASE_VICTORY_PATH);
  background_defeat.loadFromFile(renderer, FINAL_PHASE_DEFEAT_PATH);
  font = TTF_OpenFont(JAPANESE_FONT_PATH, 50);
  if (!font) {
    throw SDLException("SDLException: failed to load fonts -> FinalPhase - %s\n",TTF_GetError());
  }
}

void FinalPhase::setRound(int current_round, int total_rounds) {
  this->round = current_round;
  this->total_rounds = total_rounds;
  clean();
}

void FinalPhase::addScore(const std::string& name, bool my_team, int round_kills,
          int total_kills, int times_killed, int money, bool victory) {
  this->victory = victory;
  std::stringstream round;
  std::stringstream total;
  std::stringstream deaths;
  std::stringstream money_gained;
  round << round_kills;
  deaths << times_killed;
  total << total_kills;
  money_gained << money;
  this->names.push_back(name);
  this->my_team.push_back(my_team);
  this->round_kills.push_back(round.str());
  this->total_kills.push_back(total.str());
  this->deaths.push_back(deaths.str());
  this->money.push_back(money_gained.str());
  std::string my("");
  if (my_team) {my = " True ";} else {my = " False ";}
}

void FinalPhase::renderRequested(int x, const std::vector<std::string>& request) {
  SDL_Color white = {255, 255, 255};
  SDL_Rect quad = {0};
  quad.h = 20;
  int my_y = 230;
  int other_y = 230;
  for (unsigned int i = 0; i < request.size(); i++) {
    quad.x = x;
    if (this->my_team[i]) {quad.y = my_y;} else {quad.y = other_y;}
    if (!this->my_team[i]) {quad.x += 420;}
    quad.w = 8*request[i].size();
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, request[i].c_str(), white);
    SDL_Texture* Message = renderer.createTextureFromSurface(surfaceMessage);
    renderer.render(Message, NULL, &quad);
    if (this->my_team[i]) {my_y += 20;} else {other_y += 20;}
    SDL_FreeSurface(surfaceMessage);
  }
}

void FinalPhase::renderSquadsPoints() {
  SDL_Color white = {255, 255, 255};
  SDL_Rect quad = {0};
  quad.x = screen_width/2 - 140;
  quad.y = 115;
  quad.h = 40;
  quad.w = 24;
  std::stringstream my_wins;
  std::stringstream other_wins;
  int my_wins_to_render = (this->my_squad==1) ? this->wins_one:this->wins_two;
  my_wins << my_wins_to_render;
  int other_wins_to_render = (this->my_squad==1) ? this->wins_two:this->wins_one;
  other_wins << other_wins_to_render;
  SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, my_wins.str().c_str(), white);
  SDL_Texture* Message = renderer.createTextureFromSurface(surfaceMessage);
  renderer.render(Message, NULL, &quad);
  SDL_FreeSurface(surfaceMessage);
  quad.x = screen_width/2 + 300;
  surfaceMessage = TTF_RenderText_Solid(font, other_wins.str().c_str(), white);
  Message = renderer.createTextureFromSurface(surfaceMessage);
  renderer.render(Message, NULL, &quad);
  SDL_FreeSurface(surfaceMessage);
}

void FinalPhase::renderBackground() {
  SDL_Rect quad = {
    screen_width/2 - BACKGROUND_WIDTH/2,
    screen_height/2 - BACKGROUND_HEIGHT/2,
    BACKGROUND_WIDTH,
    BACKGROUND_HEIGHT
  };
  if (this->victory) { renderer.render(background_victory.getTexture(), NULL, &quad); }
  else { renderer.render(background_defeat.getTexture(), NULL, &quad); }
}

void FinalPhase::setPlayerSquad(int squad) { this->my_squad = squad; }

void FinalPhase::setSquadsPoints(int wins_one, int wins_two) {
  this->wins_one = wins_one;
  this->wins_two = wins_two;
}

void FinalPhase::renderRounds() {
  SDL_Color white = {255, 255, 255};
  SDL_Rect quad = {0};
  quad.x = screen_width/2 - 100 + 425;
  quad.y = 548;
  quad.h = 15;
  quad.w = 8;
  std::stringstream round_stream;
  round_stream << this->round;
  SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, round_stream.str().c_str(), white);
  SDL_Texture* Message = renderer.createTextureFromSurface(surfaceMessage);
  renderer.render(Message, NULL, &quad);
  SDL_FreeSurface(surfaceMessage);
  quad.x += 30;
  quad.w = 16;
  std::stringstream total;
  total << total_rounds;
  surfaceMessage = TTF_RenderText_Solid(font, total.str().c_str(), white);
  Message = renderer.createTextureFromSurface(surfaceMessage);
  renderer.render(Message, NULL, &quad);
  SDL_FreeSurface(surfaceMessage);
}

void FinalPhase::renderRound() {
  renderBackground();
  renderRequested(screen_width/2 - 380, names);
  renderRequested(screen_width/2 - 290, round_kills);
  renderRequested(screen_width/2 - 220, total_kills);
  renderRequested(screen_width/2 - 150, deaths);
  renderRequested(screen_width/2 - 100, money);
  renderRounds();
  renderSquadsPoints();
}

void FinalPhase::clean() {
  this->names.clear();
  this->money.clear();
  this->deaths.clear();
  this->round_kills.clear();
  this->total_kills.clear();
}


void FinalPhase::render() {
  renderRound();
}

void FinalPhase::endGame() { this->post_game = true; }

FinalPhase::~FinalPhase() {
  if (font != NULL) { TTF_CloseFont(font); }
  background_victory.free();
  background_defeat.free();
}
