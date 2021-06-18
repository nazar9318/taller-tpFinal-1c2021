#include "StartGameHandler.h"

StartGameHandler::StartGameHandler(std::vector<char> message, int id):msg(message), id(id){

}

void StartGameHandler::handle(){
  // std::cout << "Aca manejamos el evento: "<< msg[0] << '\n';
}

StartGameHandler::~StartGameHandler(){}
