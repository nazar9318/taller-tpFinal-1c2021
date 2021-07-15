#include "FinalPhase.h"
#include <iostream>

FinalPhase::FinalPhase(Renderer& renderer, int screen_width, int screen_height):
renderer(renderer), screen_width(screen_width), screen_height(screen_height),
font(NULL), post_game(false) {
  names.push_back("Nombre");
  team.push_back("Bando");
  squad.push_back("Equipo");
  money.push_back("Dinero");
  deaths.push_back("Muertes");
  round_kills.push_back("Puntos Ronda");
  total_kills.push_back("Puntos Total");
}

void FinalPhase::loadMedia() {
  background.loadFromFile(renderer, "../Client/Assets/InitialPhase/background.png");
  font = TTF_OpenFont("../Client/Assets/Fonts/japanese.ttf", 35);
  if (!font) {
    throw SDLException("SDLException: failed to load fonts -> FinalPhase - %s\n",TTF_GetError());
  }
}

void FinalPhase::addScore(const std::string& name, const std::string& team,
                          int squad, int round_kills, int total_kills) {
  std::stringstream round;
  std::stringstream squad_team;
  std::stringstream total;
  round << round_kills;
  total << total_kills;
  squad_team << "Equipo " << squad;
  this->names.push_back(name);
  this->squad.push_back(squad_team.str());
  this->team.push_back(team);
  this->round_kills.push_back(round.str());
  this->total_kills.push_back(total.str());
}

void FinalPhase::renderSquadScores() {
  unsigned int one = 0;
  unsigned int two = 0;
  for (unsigned int i = 1; i < names.size(); i++) {
    if (team[i].compare("Equipo 1") == 0) {
      one += std::stoi(total_kills[i]);
    } else {
      two += std::stoi(total_kills[i]);
    }
  }
  std::stringstream one_cnt;
  std::stringstream two_cnt;
  one_cnt << "Equipo 1: " << one;
  two_cnt << "Equipo 2: " << two;
  std::vector<std::string> team_scores;
  team_scores.push_back("Puntos equipo");
  team_scores.push_back(one_cnt.str());
  team_scores.push_back(two_cnt.str());
  renderRequested(screen_width/2 + 300, team_scores);
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
  team_scores.push_back("Puntos bando");
  team_scores.push_back(counter_cnt.str());
  team_scores.push_back(terrorist_cnt.str());
  renderRequested(screen_width/2 + 200, team_scores);
}

void FinalPhase::renderRequested(int x, const std::vector<std::string>& request) {
  SDL_Color white = {255, 255, 255};
  SDL_Rect quad = {0};
  quad.x = x;
  quad.y = 0;
  quad.h = 15;
  for (unsigned int i = 0; i < request.size(); i++) {
    quad.w = 7*request[i].size();
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, request[i].c_str(), white);
    SDL_Texture* Message = renderer.createTextureFromSurface(surfaceMessage);
    renderer.render(Message, NULL, &quad);
    quad.y += 40;
    SDL_FreeSurface(surfaceMessage);
  }
}

void FinalPhase::renderRound() {
  SDL_Rect quad = {
    screen_width/2 - BACKGROUND_WIDTH/2,
    screen_height/2 - BACKGROUND_HEIGHT/2, 
    BACKGROUND_WIDTH,
    40*(int)this->names.size()
  };
  renderer.render(background.getTexture(), NULL, &quad);
  renderRequested(screen_width/2 - 400, names);
  renderRequested(screen_width/2 - 300, team);
  renderRequested(screen_width/2 - 200, squad);
  renderRequested(screen_width/2 - 120, money);
  renderRequested(screen_width/2 - 70, deaths);
  renderRequested(screen_width/2, round_kills);
  renderRequested(screen_width/2 + 100, total_kills);
  renderTeamScores();
  renderSquadScores();
}

void FinalPhase::clean() {
  this->names.clear();
  this->team.clear();
  this->round_kills.clear();
  this->deaths.clear();
  this->money.clear();
  this->total_kills.clear();
  this->squad.clear();
  names.push_back("Nombre");
  team.push_back("Bando");
  squad.push_back("Equipo");
  money.push_back("Dinero");
  deaths.push_back("Muertes");
  round_kills.push_back("Puntos Ronda");
  total_kills.push_back("Puntos Total");
}

void FinalPhase::teamWinner(std::string& winner, int& count) {
  unsigned int one = 0;
  unsigned int two = 0;
  for (unsigned int i = 1; i < names.size(); i++) {
    if (squad[i].compare("Equipo 1") == 0) {
      one += std::stoi(total_kills[i]);
    } else {
      two += std::stoi(total_kills[i]);
    }
  }
  if (one > two) {
    winner = "Equipo 1";
    count = one;
  } else {
    winner = "Equipo 2";
    count = two;
  }
}

void FinalPhase::playerWinner(std::string& winner, int& count) {
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
  std::string team_winner;
  int player_count = 0;
  int team_count = 0;
  std::vector<std::string> player_scores;
  playerWinner(player_winner, player_count);
  std::stringstream player_cnt;
  player_cnt << player_winner << ": " << player_count;
  player_scores.push_back("Jugador ganador");
  player_scores.push_back(player_cnt.str());
  teamWinner(team_winner, team_count);
  std::stringstream terrorist_cnt;
  terrorist_cnt << team_winner << " con " << team_count << " puntos";
  std::vector<std::string> team_scores;
  team_scores.push_back("Equipo ganador");
  team_scores.push_back(terrorist_cnt.str());
  renderRequested(screen_width/2-200, player_scores);
  renderRequested(screen_width/2+100, team_scores);
}

void FinalPhase::render() { post_game ? renderPostGame() : renderRound(); }

void FinalPhase::endGame() { this->post_game = true; }

FinalPhase::~FinalPhase() {
  if (font != NULL) { TTF_CloseFont(font); }
}
