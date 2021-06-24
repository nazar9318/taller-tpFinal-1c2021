#include "StartGameEvent.h"
#include <stdio.h>

StartGameEvent::StartGameEvent(){
  msg.push_back(ClientTypeEvent::START_GAME); //Agrego el tipo de evento
}

StartGameEvent::~StartGameEvent(){}
