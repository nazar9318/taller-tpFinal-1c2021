#include "StartGameEvent.h"

StartGameEvent::StartGameEvent(){
  msg.push_back((char)TypeOfEvent::START_GAME); //Agrego el tipo de evento
  // msg.push_back(direction.get_x());
  // msg.push_back(direction.get_y());
}

ClientEvent StartGameEvent::get_event(){
  return ClientEvent(msg, msg.size());
}

StartGameEvent::~StartGameEvent(){}
