#ifndef _SEND_FULL_MAP_EVENT_H
#define _SEND_FULL_MAP_EVENT_H

#include "TypesOfEvents.h"
#include "Event.h"
#include <vector>
#include <string>
#include "Position.h"


class SendFullMapEvent: public Event {
	public:
		// Descripcion: Envia todos las posiciones del mapa que son estaticas
		//              y no cambiaran a lo largo de las rondas, ni durante las
		//              partidas. 
		// POST: El mensaje es de la forma: 
		//       ancho(int), largo(int), pos0x(int), pos0y(int), type0,
		//                               pos1x(int), pos1y(int), type1, ...
		SendFullMapEvent(std::vector<Position*> map_info,
			 int x_lenght, int y_lenght);
		~SendFullMapEvent();
	private:
		SendFullMapEvent(const SendFullMapEvent &other) = delete;
		SendFullMapEvent& operator=(const SendFullMapEvent &other) = delete;
};

#endif
