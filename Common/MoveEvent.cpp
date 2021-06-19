#include "MoveEvent.h"

MoveEvent::MoveEvent(/*Direction& direction*/){
  msg.push_back((char)TypeOfEvent::MOVE); //Agrego el tipo de evento
  // msg.push_back(direction.get_x());
  // msg.push_back(direction.get_y());
}

Event MoveEvent::get_event(){
  return Event(msg, msg.size());
}

MoveEvent::~MoveEvent(){}
