#include "Client.h"

Client::Client(const std::string& host, const std::string& port) {}
		
		
void Client::execute() {
	bool game_started = execute_lobby();
	if (game_started)
		execute_game();
}



bool Client::execute_lobby() { 
	bool is_logged = false;
	// logica de la inicializacion
	return is_logged;
}



void Client::execute_game() { }




Client::~Client() {}
