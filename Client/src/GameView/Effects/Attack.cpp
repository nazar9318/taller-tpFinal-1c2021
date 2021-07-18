#include "Attack.h"

Attack::Attack(char id_receiver, char id_attacker):
  id_receiver(id_receiver),
  id_attacker(id_attacker),
  ticks(0){}

char Attack::getReceiverId(){
  return id_receiver;
}

char Attack::getAttackerId(){
  return id_attacker;
}

bool Attack::addTick(){
  ticks += 1;
  if(ticks == TICKS_TO_RENDER){
    return false;
  }
  return true;
}

Attack::~Attack(){}
