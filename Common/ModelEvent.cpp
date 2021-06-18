#include "ModelEvent.h"


ModelEvent::ModelEvent(TypeOfEvent t): type(t) {}

TypeOfEvent ModelEvent::get_type() {
	return type;
}


ModelEvent::~ModelEvent() {}