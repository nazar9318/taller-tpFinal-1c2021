#ifndef _CLIENT_EVENT_H
#define _CLIENT_EVENT_H

#include <string>
#include <syslog.h>

#include "TypesOfEvents.h"

class ClientEvent {
	std::string msg;
	TypeOfEvent type_msg;
	int client_id;
	public:
		ClientEvent(TypeOfEvent t);
		ClientEvent() {}
		ClientEvent(ClientEvent&&) = default;
    	ClientEvent& operator = (ClientEvent&&) = default;
    	void add_client_id(int id);
		char get_type();
		std::string to_string();

		~ClientEvent();

	private:
		ClientEvent(const ClientEvent &other) = delete;
		ClientEvent& operator=(const ClientEvent &other) = delete;
};

#endif
