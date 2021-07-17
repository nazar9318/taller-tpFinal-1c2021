#include "FinalPhase.h"
#include <iostream>

FinalPhase::FinalPhase(Renderer& renderer, int screen_width, int screen_height):
renderer(renderer), screen_width(screen_width), screen_height(screen_height),
font(NULL), post_game(false) {}

void FinalPhase::loadMedia() {
  background_victory.loadFromFile(renderer, FINAL_PHASE_VICTORY_PATH);
  background_defeat.loadFromFile(renderer, FINAL_PHASE_DEFEAT_PATH);
  font = TTF_OpenFont(JAPANESE_FONT_PATH, 50);
  if (!font) {
    throw SDLException("SDLException: failed to load fonts -> FinalPhase - %s\n",TTF_GetError());
  }
}

void FinalPhase::setRound(int current_round) {
  this->round = current_round;
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

/*void FinalPhase::renderSquadScores() {
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
}*/

/*void FinalPhase::renderTeamScores() {
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
}*/

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
  total << 10;
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

/*void FinalPhase::teamWinner(std::string& winner, int& count) {
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
}*/

/*void FinalPhase::playerWinner(std::string& winner, int& count) {
  winner = names[0];
  for (unsigned int i = 1; i < names.size(); i++) {
    if (std::stoi(total_kills[i]) > count) {
      count = std::stoi(total_kills[i]);
      winner = names[i];
    }
  }
}*/

/*void FinalPhase::renderPostGame() {
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
}*/

void FinalPhase::render() {
  renderRound();
}

void FinalPhase::endGame() { this->post_game = true; }

FinalPhase::~FinalPhase() {
  if (font != NULL) { TTF_CloseFont(font); }
  background_victory.free();
  background_defeat.free();
}
