#ifndef _PLANT_BOMB_EVENT_H
#define _PLANT_BOMB_EVENT_H

#include "TypesOfEvents.h"
#include "Event.h"
#include <string>


class PlantBombEvent: public Event {
	public:

		PlantBombEvent();
		~PlantBombEvent();
	private:
		PlantBombEvent(const PlantBombEvent &other) = delete;
		PlantBombEvent& operator=(const PlantBombEvent &other) = delete;
};

#endif
