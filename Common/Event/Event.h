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
		char client_id;

	public:
		Event(std::vector<char> msg, size_t size);
		Event();

		Event(Event&&) = default;

		Event& operator = (Event&&) = default;

		virtual void add_client_id(char id);

		virtual char get_type();
		virtual size_t get_size();
		virtual char get_id();

		virtual std::vector<char> get_msg();
		virtual char* get_data();

		~Event();

	private:
		Event(const Event &other) = delete;
		Event& operator=(const Event &other) = delete;
};

#endif
