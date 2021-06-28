#ifndef _STEP_INFORMATION_H
#define _STEP_INFORMATION_H

#include <vector>
#include <map>
#include <string>
#include "Position.h"
#include "FaseType.h"

class StepInformation {
	// id, x, y
	std::map<char, std::pair<int, int>> positions;
	FaseType fase;
	int waiting_time;
	public:
		StepInformation();
		void set_type(FaseType fase);
		FaseType get_type();
		void set_waiting_time(int wait);
		int get_waiting_time();
		void clear();
		void add_position(char id, int x, int y);
		~StepInformation();
	private:
		StepInformation(const StepInformation &other) = delete;
		StepInformation& operator=(const StepInformation &other) = delete;
};

#endif
