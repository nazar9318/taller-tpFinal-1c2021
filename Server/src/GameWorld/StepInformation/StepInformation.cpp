#include "StepInformation.h"

StepInformation::StepInformation() {
}

void StepInformation::clear() {
	//
}

void StepInformation::add_position(char id, int x, int y) {
	std::pair<int, int> pos(x, y * (-1));
	positions[id] = pos;
}

StepInformation::~StepInformation() {
}



