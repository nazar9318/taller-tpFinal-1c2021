#include "AttackEffect.h"

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
  blood.loadFromFile(renderer, "../Client/Assets/Attacks/blood.bmp", black, SDL_BLENDMODE_BLEND, 200);

  blood.setColor(red);
}

void AttackEffect::createAttack(char id_receiver, char id_attacker){
  Attack newAttack(id_receiver, id_attacker);
  attacks.push_back(std::move(newAttack));
}

void AttackEffect::render(){
  renderBlood();

}

void AttackEffect::renderBlood(){
  SDL_Rect position = {0};
  std::list<Attack> aux;
  char receiver_id;

  for (auto it = attacks.begin(); it != attacks.end(); ++it) {
    receiver_id = it->getReceiverId();
    if(receiver_id == player_id){
      position = player.getBox();
    } else{
      position = characters.at(receiver_id).getBox();
    }
    SDL_Rect quad = {position.x + PLAYER_WIDTH/2, position.y + PLAYER_HEIGHT/2, BLOOD_WIDTH, BLOOD_HEIGHT};
    camera.renderAddingOffset(blood.getTexture(), quad);

    if(it->addTick()){
      aux.push_back(std::move(*it));
    }
  }

  attacks.swap(aux);
}

AttackEffect::~AttackEffect(){

}
