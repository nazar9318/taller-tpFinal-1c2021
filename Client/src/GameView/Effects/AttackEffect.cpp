#include "AttackEffect.h"

#define FROM_RAD_TO_DEG 57.295779513

AttackEffect::AttackEffect(Renderer& renderer, Camera& camera, char player_id, ClientPlayer& player,
  std::map<char, ClientCharacter>& characters):
  renderer(renderer),
  camera(camera),
  player_id(player_id),
  player(player),
  characters(characters){}


void AttackEffect::loadMedia(){

  Color red = {0x87,0x14,0x14};
  Color black = {0x00,0x00,0x00};
  blood.loadFromFile(renderer, ATTACK_BLOOD_PATH, black, SDL_BLENDMODE_BLEND, 200);

  arrow.loadFromFile(renderer, ATTACK_ARROW_PATH, black, SDL_BLENDMODE_BLEND, 200);

  blood.setColor(red);
  arrow.setColor(red);
}

void AttackEffect::createAttack(char id_receiver, char id_attacker){
  Attack newAttack(id_receiver, id_attacker);
  attacks.push_back(std::move(newAttack));
}

void AttackEffect::render(){
  SDL_Rect receiver_pos = {0};
  std::list<Attack> aux;
  char receiver_id;

  for (auto it = attacks.begin(); it != attacks.end(); ++it) {
    receiver_id = it->getReceiverId();
    if(receiver_id == player_id){
      receiver_pos = player.getBox();
    } else{
      receiver_pos = characters.at(receiver_id).getBox();
    }

    renderBlood(receiver_pos);

    if(it->addTick()){
      aux.push_back(std::move(*it));
    }
  }

  attacks.swap(aux);
}

void AttackEffect::renderBlood(SDL_Rect& position){
  SDL_Rect quad = {position.x, position.y, BLOOD_WIDTH/2, BLOOD_HEIGHT/2};
  camera.renderAddingOffset(blood.getTexture(), quad);
}

AttackEffect::~AttackEffect(){

}
