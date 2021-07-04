#ifndef STOP_PLANT_BOMB_EVENT_H
#define STOP_PLANT_BOMB_EVENT_H

#include "TypesOfEvents.h"
#include "Event.h"
#include <string>


class StopPlantBombEvent: public Event {
	public:
		StopPlantBombEvent();
		~StopPlantBombEvent();
	private:
		StopPlantBombEvent(const StopPlantBombEvent &other) = delete;
		StopPlantBombEvent& operator=(const StopPlantBombEvent &other) = delete;
};

#endif
