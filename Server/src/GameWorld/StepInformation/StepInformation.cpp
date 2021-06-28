#include "StepInformation.h"

StepInformation::StepInformation() {
}

void StepInformation::clear() {
	//
}

void StepInformation::set_type(FaseType fase_type) {
	fase = fase_type;
}

FaseType StepInformation::get_type() {
	return fase;
}

void StepInformation::set_waiting_time(int wait) {
	waiting_time = wait;
}

int StepInformation::get_waiting_time() {
	return waiting_time;
}

void StepInformation::add_position(char id, int x, int y) {
	std::pair<int, int> pos(x, y * (-1));
	positions[id] = pos;
}

StepInformation::~StepInformation() {
}



