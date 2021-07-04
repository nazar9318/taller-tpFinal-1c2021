#ifndef START_PLANT_BOMB_EVENT_H
#define START_PLANT_BOMB_EVENT_H

#include "TypesOfEvents.h"
#include "Event.h"
#include <string>

class StartPlantBombEvent: public Event {
	public:
		StartPlantBombEvent();
		~StartPlantBombEvent();
	private:
		StartPlantBombEvent(const StartPlantBombEvent &other) = delete;
		StartPlantBombEvent& operator=(const StartPlantBombEvent &other) = delete;
};

#endif
