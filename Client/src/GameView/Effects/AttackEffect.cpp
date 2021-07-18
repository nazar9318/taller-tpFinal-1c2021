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
  SDL_Rect attacker_pos = {0};
  std::list<Attack> aux;
  char receiver_id;
  char attacker_id;

  for (auto it = attacks.begin(); it != attacks.end(); ++it) {
    receiver_id = it->getReceiverId();
    attacker_id = it->getAttackerId();

    if(receiver_id != player_id && attacker_id != player_id){
      receiver_pos = characters.at(receiver_id).getBox();
      attacker_pos = characters.at(attacker_id).getBox();
    } else if(receiver_id == player_id){
      receiver_pos = player.getBox();
      attacker_pos = characters.at(attacker_id).getBox();
      renderArrow(receiver_pos, attacker_pos);
    } else if(attacker_id == player_id){
      receiver_pos = characters.at(receiver_id).getBox(); //PUEDO SACAR LA CONDICION DE ESTE IF Y DEJAR
      attacker_pos = player.getBox();                     // SOLO EL RECEIVER POS
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

void AttackEffect::renderArrow(SDL_Rect& receiver_pos, SDL_Rect& attacker_pos){
  int delta_x, delta_y;
  double angle;

  delta_x = receiver_pos.x - attacker_pos.x;
  delta_y = receiver_pos.y - attacker_pos.y;
  angle = (int)((atan2(delta_y, delta_x) * FROM_RAD_TO_DEG))-90;

  // offset_x = cos((angle+90) * FROM_RAD_TO_DEG)*18;
  // offset_y = sin((angle+90) * FROM_RAD_TO_DEG)*18;

  SDL_Rect quad = {receiver_pos.x + receiver_pos.w/2 , receiver_pos.y + receiver_pos.h/2,
                  arrow.get_w(), arrow.get_h()};

  camera.renderAddingOffset(arrow.getTexture(), quad, NULL, angle);


  //la punta de la flecha esta en el (4 , 16)
}

// void AttackEffect::renderBlood(){
//   SDL_Rect position = {0};
//   std::list<Attack> aux;
//   char receiver_id;
//
//   for (auto it = attacks.begin(); it != attacks.end(); ++it) {
//     receiver_id = it->getReceiverId();
//     if(receiver_id == player_id){
//       position = player.getBox();
//     } else{
//       position = characters.at(receiver_id).getBox();
//     }
//     SDL_Rect quad = {position.x, position.y, BLOOD_WIDTH/2, BLOOD_HEIGHT/2};
//     camera.renderAddingOffset(blood.getTexture(), quad);
//
//     if(it->addTick()){
//       aux.push_back(std::move(*it));
//     }
//   }
//
//   attacks.swap(aux);
// }

AttackEffect::~AttackEffect(){

}
