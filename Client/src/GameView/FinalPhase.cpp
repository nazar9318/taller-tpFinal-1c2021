#include "FinalPhase.h"
#include <iostream>

FinalPhase::FinalPhase(Renderer& renderer, int screen_width, int screen_height):
renderer(renderer), screen_width(screen_width), screen_height(screen_height),
font(NULL), post_game(false) {
  names.push_back("Nombre");
  team.push_back("Equipo");
  round_kills.push_back("Ronda");
  total_kills.push_back("Total");
}

void FinalPhase::loadMedia() {
  font = TTF_OpenFont("../Client/Assets/Fonts/japanese.ttf", 30);
  if (!font) {
    throw SDLException("SDLException: failed to load fonts -> FinalPhase - %s\n",TTF_GetError());
  }
}

void FinalPhase::addScore(const std::string& name,
      const std::string& team, int round_kills, int total_kills) {
  std::stringstream round;
  std::stringstream total;
  round << round_kills;
  total << total_kills;
  this->names.push_back(name);
  this->team.push_back(team);
  this->round_kills.push_back(round.str());
  this->total_kills.push_back(total.str());
}
void FinalPhase::renderTeamScores() {
  unsigned int terrorist_count = 0;
  unsigned int counter_count = 0;
  for (unsigned int i = 1; i < names.size(); i++) {
    if (team[i].compare("Counter") == 0) {
      counter_count += std::stoi(total_kills[i]);
    } else {
      terrorist_count += std::stoi(total_kills[i]);
    }
  }
  std::stringstream counter_cnt;
  std::stringstream terrorist_cnt;
  counter_cnt << "Counter: " << counter_count;
  terrorist_cnt << "Terrorist: " << terrorist_count;
  std::vector<std::string> team_scores;
  team_scores.push_back("Puntos por equipo");
  team_scores.push_back(counter_cnt.str());
  team_scores.push_back(terrorist_cnt.str());
  renderRequested(screen_width/2 + 150, team_scores);
}

void FinalPhase::renderRequested(int x, const std::vector<std::string>& request) {
  SDL_Color white = {255, 255, 255};
  SDL_Rect quad = {0};
  quad.x = x;
  quad.y = 0;
  quad.h = 20;
  for (unsigned int i = 0; i < request.size(); i++) {
    quad.w = 8*request[i].size();
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, request[i].c_str(), white);
    SDL_Texture* Message = renderer.createTextureFromSurface(surfaceMessage);
    renderer.render(Message, NULL, &quad);
    quad.y += 40;
    SDL_FreeSurface(surfaceMessage);
  }
}

void FinalPhase::renderRound() {
  renderRequested(screen_width/2 - 400, names);
  renderRequested(screen_width/2 - 200, team);
  renderRequested(screen_width/2 - 100, round_kills);
  renderRequested(screen_width/2, total_kills);
  renderTeamScores();
}

void FinalPhase::clean() {
  this->names.clear();
  this->team.clear();
  this->round_kills.clear();
  this->total_kills.clear();
  names.push_back("Nombre");
  team.push_back("Equipo");
  round_kills.push_back("Ronda");
  total_kills.push_back("Totales");
}

void FinalPhase::teamWinner(std::string& winner, int count) {
  unsigned int terrorist_count = 0;
  unsigned int counter_count = 0;
  for (unsigned int i = 1; i < names.size(); i++) {
    if (team[i].compare("Counter") == 0) {
      counter_count += std::stoi(total_kills[i]);
    } else {
      terrorist_count += std::stoi(total_kills[i]);
    }
  }
  if (counter_count > terrorist_count) {
    winner = "Counter";
    count = counter_count;
  } else {
    winner = "Terrorist";
    count = terrorist_count;
  }
}

void FinalPhase::playerWinner(std::string& winner, int count) {
  winner = names[0];
  for (unsigned int i = 1; i < names.size(); i++) {
    if (std::stoi(total_kills[i]) > count) {
      count = std::stoi(total_kills[i]);
      winner = names[i];
    }
  }
}

void FinalPhase::renderPostGame() {
  std::string player_winner;
  std::string player_winner_title = "Jugador ganador";
  std::string team_winner;
  std::string team_winner_title = "Equipo ganador";
  int player_count = 0;
  int team_count = 0;
  playerWinner(player_winner, player_count);
  teamWinner(team_winner, team_count);
  SDL_Color white = {255, 255, 255};

  SDL_Rect quad_post_game_player = {0};
  quad_post_game_player.x = screen_width/2 - 100;
  quad_post_game_player.y = 0;
  quad_post_game_player.h = 40;
  quad_post_game_player.w = 15*player_winner_title.size();
  SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, player_winner_title.c_str(), white);
  SDL_Texture* Message = renderer.createTextureFromSurface(surfaceMessage);
  renderer.render(Message, NULL, &quad_post_game_player);
  quad_post_game_player.y += 40;
  SDL_FreeSurface(surfaceMessage);
  quad_post_game_player.w = 15*player_winner.size();
  surfaceMessage = TTF_RenderText_Solid(font, player_winner.c_str(), white);
  Message = renderer.createTextureFromSurface(surfaceMessage);
  renderer.render(Message, NULL, &quad_post_game_player);
  SDL_FreeSurface(surfaceMessage);

  SDL_Rect quad_post_game_team = {0};
  quad_post_game_team.x = screen_width/2 + 100;
  quad_post_game_team.y = 0;
  quad_post_game_team.h = 40;
  quad_post_game_team.w = 15*team_winner_title.size();
  surfaceMessage = TTF_RenderText_Solid(font, team_winner_title.c_str(), white);
  Message = renderer.createTextureFromSurface(surfaceMessage);
  renderer.render(Message, NULL, &quad_post_game_team);
  quad_post_game_team.y += 40;
  SDL_FreeSurface(surfaceMessage);
  quad_post_game_team.w = 15*team_winner.size();
  surfaceMessage = TTF_RenderText_Solid(font, team_winner.c_str(), white);
  Message = renderer.createTextureFromSurface(surfaceMessage);
  renderer.render(Message, NULL, &quad_post_game_team);
  SDL_FreeSurface(surfaceMessage);
}

void FinalPhase::render() { post_game ? renderPostGame() : renderRound(); }

void FinalPhase::endGame() { this->post_game = true; }

FinalPhase::~FinalPhase() {
  if (font != NULL) { TTF_CloseFont(font); }
}
