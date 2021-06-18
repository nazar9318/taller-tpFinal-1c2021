#ifndef _CLIENT_EVENT_H
#define _CLIENT_EVENT_H

#include <string>
#include <vector>
#include <syslog.h>

#include "TypesOfEvents.h"

class ClientEvent {

	private:
		std::vector<char> msg;
		size_t size;
		int client_id;

	public:
		ClientEvent(std::vector<char> msg, size_t size);
		ClientEvent();

		ClientEvent(ClientEvent&&) = default;

		ClientEvent& operator = (ClientEvent&&) = default;

		void add_client_id(int id);

		char get_type();

		int get_id();

		std::vector<char> to_string();

		~ClientEvent();

	private:
		ClientEvent(const ClientEvent &other) = delete;
		ClientEvent& operator=(const ClientEvent &other) = delete;
};

#endif
