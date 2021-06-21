#ifndef _EVENT_H
#define _EVENT_H

#include <string>
#include <vector>
#include <syslog.h>

#include "TypesOfEvents.h"

class Event {

	protected:
		std::vector<char> msg;
		size_t size;
		int client_id;

	public:
		Event(std::vector<char> msg, size_t size);
		Event();

		Event(Event&&) = default;

		Event& operator = (Event&&) = default;

		void add_client_id(int id);

		char get_type();
		size_t get_size();
		int get_id();

		std::vector<char> get_msg();

		~Event();

	private:
		Event(const Event &other) = delete;
		Event& operator=(const Event &other) = delete;
};

#endif
