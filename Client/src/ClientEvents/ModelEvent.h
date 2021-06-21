#ifndef _MODEL_EVENT_H
#define _MODEL_EVENT_H

#include <string>
#include <vector>
#include "TypesOfEvents.h"

class ModelEvent {
	std::vector<char> msg;
	size_t size;
	public:

		ModelEvent(std::vector<char> msg, size_t size);
		ModelEvent();

		char get_type();

		std::vector<char> get_msg();

		ModelEvent(ModelEvent&&) = default;
    ModelEvent& operator= (ModelEvent&&) = default;

		~ModelEvent();

	private:
		ModelEvent(const ModelEvent &other) = delete;
		ModelEvent& operator=(const ModelEvent &other) = delete;
};

#endif
