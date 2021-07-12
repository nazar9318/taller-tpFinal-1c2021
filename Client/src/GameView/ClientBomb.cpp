#include "ClientBomb.h"

ClientBomb::ClientBomb(Renderer& renderer,Camera& camera, char player_id, ClientPlayer& player):
  renderer(renderer),
  camera(camera),
  player_id(player_id),
  player(player),
  has_owner(false),
  state(BombState::NORMAL)
  {}

void ClientBomb::loadClips(){
  for (int i = 0; i < 10; i++) {
    progress_bar_clips[i].x = 0;
    progress_bar_clips[i].y = i*101;
    progress_bar_clips[i].w = 737;
    progress_bar_clips[i].h = 101;
  }
}


void ClientBomb::loadMedia(){

  progress_bar.loadFromFile(renderer, "../Client/Assets/Bomb/progress_bars.png");

  loadClips();
}

void ClientBomb::set_normal_state(bool has_owner, char id_owner, int x_pos, int y_pos){
  this->state = BombState::NORMAL;
  this->has_owner = has_owner;
  this->id_owner = id_owner;
  player.change_bomb_ownership(false);

  if(has_owner){
    if(id_owner == player_id){
      player.change_bomb_ownership(true);
    }
  } else {
    player.change_bomb_ownership(false);
    this->x = x_pos;
    this->y = y_pos;
  }
}

void ClientBomb::set_activating_state(char id_owner, int percentage){
  this->state = BombState::ACTIVATING;
  this->id_owner = id_owner;
  this->percentage = percentage;
}

void ClientBomb::set_deactivating_state(char id_owner, int percentage){
  this->state = BombState::DEACTIVATING;
  this->id_owner = id_owner;
  this->percentage = percentage;
}

void ClientBomb::render(){
  if(state == BombState::NORMAL && !has_owner){
    // renderizo en piso
  }

  if(state == BombState::ACTIVATING && id_owner == player_id){
    render_activating_bomb();
  }

  if(state == BombState::DEACTIVATING && id_owner == player_id){
    render_deactivating_bomb();
  }

}

void ClientBomb::render_activating_bomb(){
  SDL_Rect current_clip = {0};

  int clip = (int)(percentage/10);
  current_clip = progress_bar_clips[clip];

  SDL_Rect player_pos = player.getBox();
  int bar_width = 147;
  int bar_height = 20;

  SDL_Rect quad = {player_pos.x - bar_width/3 , player_pos.y - 20, bar_width, bar_height};
  camera.renderAddingOffset(progress_bar.getTexture(), quad, &current_clip);

}

void ClientBomb::render_deactivating_bomb(){
  SDL_Rect current_clip = {0};

  int clip = (int)(percentage/10);
  current_clip = progress_bar_clips[clip];

  SDL_Rect player_pos = player.getBox();
  int bar_width = 147;
  int bar_height = 20;

  SDL_Rect quad = {player_pos.x - bar_width/3 , player_pos.y - 20, bar_width, bar_height};
  camera.renderAddingOffset(progress_bar.getTexture(), quad, &current_clip);

}

ClientBomb::~ClientBomb(){

}
