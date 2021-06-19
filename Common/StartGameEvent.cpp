#include "StartGameEvent.h"
#include <stdio.h>

StartGameEvent::StartGameEvent(){
  msg.push_back(TypeOfEvent::START_GAME); //Agrego el tipo de evento
}

Event StartGameEvent::get_event(){
  return Event(msg, msg.size());
}

StartGameEvent::~StartGameEvent(){}
