#include "SendFullMapEvent.h"

// Descripcion: Envia todos las posiciones del mapa que son estaticas
//              y no cambiaran a lo largo de las rondas, ni durante las
//              partidas. 
// POST: El mensaje es de la forma: 
//       ancho(int), largo(int), pos0x(int), pos0y(int), type0,
//                               pos1x(int), pos1y(int), type1, ...
SendFullMapEvent::SendFullMapEvent(std::vector<Position*> map_info,
			 int x_lenght, int y_lenght) {
	this->msg.push_back((char)ModelTypeEvent::SEND_FULL_MAP);
	push_back(x_lenght);
	push_back(y_lenght);

	for (auto it = map_info.begin(); it != map_info.end(); ++it) {
		int x_pos = (*it)->get_x();
		int y_pos = (-1) * (*it)->get_y();
		char type = (*it)->get_type();
		push_back(x_pos);
		push_back(y_pos);
		this->msg.push_back(type);
	}
}

SendFullMapEvent::~SendFullMapEvent() {}
