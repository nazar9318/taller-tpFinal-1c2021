#include "MoveHandler.h"

MoveHandler::MoveHandler(std::vector<char> message, int id):msg(message), id(id){}

void MoveHandler::handle(){
  // std::cout << "Aca manejamos el evento: "<< msg[0] << '\n';
}

MoveHandler::~MoveHandler(){}
