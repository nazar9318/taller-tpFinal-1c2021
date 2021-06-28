#ifndef _STEP_INFORMATION_H
#define _STEP_INFORMATION_H

#include <vector>
#include <map>
#include <string>
#include "Position.h"


class StepInformation {
	// id, x, y
	std::map<char, std::pair<int, int>> positions;
	public:
		StepInformation();
		void clear();
		void add_position(char id, int x, int y);
		~StepInformation();
	private:
		StepInformation(const StepInformation &other) = delete;
		StepInformation& operator=(const StepInformation &other) = delete;
};

#endif
