#include "ClientBomb.h"

ClientBomb::ClientBomb(Renderer& renderer,Camera& camera, char player_id, ClientPlayer& player):
  renderer(renderer),
  camera(camera),
  player_id(player_id),
  player(player),
  has_owner(false),
  state(BombState::NORMAL)
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
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if(!(i == 4 && (j == 3 || j == 4))){
        explosion_clips[i].x = j*EXPLOSION_WIDTH;
        explosion_clips[i].y = i*EXPLOSION_HEIGHT;
        explosion_clips[i].w = EXPLOSION_WIDTH;
        explosion_clips[i].h = EXPLOSION_HEIGHT;
      }
    }
  }
}


void ClientBomb::loadMedia(){
  Color black_color = {0x00, 0x00, 0x00};

  progress_bar.loadFromFile(renderer, "../Client/Assets/Bomb/progress_bars.png");
  bomb_in_ground.loadFromFile(renderer, "../Client/Assets/Bomb/bomb_d.bmp", black_color);
  explosion.loadFromFile(renderer, "../Client/Assets/Bomb/explosion.png");

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
  camera.render(bomb_in_ground.getTexture(), quad, NULL);
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
  SDL_Rect quad = {x, y, EXPLOSION_WIDTH, EXPLOSION_HEIGHT};
  // SDL_Rect clip = {0, 0, EXPLOSION_WIDTH, EXPLOSION_HEIGHT};

  for (int i = 0; i < EXPLOSION_CLIPS; i++) {
    camera.render(explosion.getTexture(), quad, &explosion_clips[i]);
  }
  // camera.render(explosion.getTexture(), quad, &clip);
}

ClientBomb::~ClientBomb(){

}
