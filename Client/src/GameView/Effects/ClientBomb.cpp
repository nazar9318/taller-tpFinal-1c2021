#include "ClientBomb.h"

ClientBomb::ClientBomb(Renderer& renderer,Camera& camera, char player_id, ClientPlayer& player):
  renderer(renderer),
  camera(camera),
  player_id(player_id),
  player(player),
  has_owner(false),
  state(BombState::NORMAL),
  ticks(0)
  {}

void ClientBomb::loadBarClips(){
  for (int i = 0; i < 10; i++) {
    progress_bar_clips[i].x = 0;
    progress_bar_clips[i].y = i*BAR_HEIGHT;
    progress_bar_clips[i].w = BAR_WIDTH;
    progress_bar_clips[i].h = BAR_HEIGHT;
  }
}

void ClientBomb::loadExplosionClips() {
  /*cada clip es de 64x64 y hay 5 5 5 5 3*/
  int pos = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if(!(i == 4 && (j == 3 || j == 4))){
        explosion_clips[pos].x = j*EXPLOSION_WIDTH;
        explosion_clips[pos].y = i*EXPLOSION_HEIGHT;
        explosion_clips[pos].w = EXPLOSION_WIDTH;
        explosion_clips[pos].h = EXPLOSION_HEIGHT;
        pos++;
      }
    }
  }
}


void ClientBomb::loadMedia(){
  Color black_color = {0x00, 0x00, 0x00};

  progress_bar.loadFromFile(renderer, PROGRESS_BARS_PATH);
  bomb_in_ground.loadFromFile(renderer, BOMB_GROUND_PATH, black_color);
  explosion.loadFromFile(renderer, BOMB_EXPLOSION_PATH);

  loadBarClips();
  loadExplosionClips();
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

void ClientBomb::set_activated_state(char id_owner, int x, int y, int time_until_explote){
  this->state = BombState::ACTIVATED;
  this->id_owner = id_owner;
  this->x = x;
  this->y = y;
  has_owner = false;
  if(id_owner == player_id){
    player.change_bomb_ownership(false);
  }
}

void ClientBomb::set_exploted_state(){
  ticks = 0;
  this->state = BombState::EXPLOTED;
}

void ClientBomb::set_deactivated_state(){
  this->state = BombState::DEACTIVATED;
}

void ClientBomb::render(){
  if(state == BombState::NORMAL && !has_owner){
    render_bomb_in_ground();
  }

  if(state == BombState::ACTIVATING && id_owner == player_id){
    render_activating_bomb();
  }

  if(state == BombState::DEACTIVATING && id_owner == player_id){
    render_deactivating_bomb();
  }

  if(state == BombState::EXPLOTED){
    render_explosion();
  }

}

void ClientBomb::render_bomb_in_ground(){
  SDL_Rect quad = {x ,y, bomb_in_ground.get_w(), bomb_in_ground.get_h()};
  camera.renderAddingOffset(bomb_in_ground.getTexture(), quad, NULL);
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

void ClientBomb::render_explosion(){

  if(ticks >= EXPLOSION_TICKS){
    return;
  }

  SDL_Rect quad = {x - EXPLOSION_WIDTH/2, y - EXPLOSION_HEIGHT/2, EXPLOSION_WIDTH, EXPLOSION_HEIGHT};
  int current_clip;

  if(ticks%2 == 0) {
    current_clip = ticks/2;
  } else {
    current_clip = (ticks-1)/2;
  }

  camera.renderAddingOffset(explosion.getTexture(), quad, &explosion_clips[current_clip]);
  ticks += 1;
}

ClientBomb::~ClientBomb(){

}
