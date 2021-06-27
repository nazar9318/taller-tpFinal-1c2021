#ifndef _STEP_INFORMATION_H
#define _STEP_INFORMATION_H

#include <vector>
#include <string>
#include "Position.h"


class StepInformation {
	public:
		StepInformation();
		~StepInformation();
	private:
		StepInformation(const StepInformation &other) = delete;
		StepInformation& operator=(const StepInformation &other) = delete;
};

#endif
