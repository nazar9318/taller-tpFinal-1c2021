#include "Lobby.h"



Lobby::Lobby(ProtectedQueue<ModelEvent>& model,
		 ProtectedQueue<ClientEvent>& client, GameMap& game_map):
		  model_events(model), client_events(client), map(game_map) {
}
		
// returns true if player is logged in. 
bool Lobby::launch(Socket& socket) {
	// CONEXION SINCRONICA: SEND-RECV
	// LOGICA DE BIENVENIDA
	// QAPPLICATION
	// SERIA: 1) blocking_pop DE MODEL_EVENTS que devuelve los LOS MAPAS QUE
	// 		  SE PUEDEN IMPRIMIR y las partidas creadas, etc. 
	//        2) leer un evento para unirse/ crear partida
	//        3) pushear el evento a client_events
	//        4) hacer loop hasta que se inicialice el map y se pueda jugar. 
	//        5) si hay un quit() hay que salir de la partida.  
	return true;
}

Lobby::~Lobby() {}