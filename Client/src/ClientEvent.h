#ifndef _CLIENT_EVENT_H
#define _CLIENT_EVENT_H

#include <string>
#include <syslog.h>



class ClientEvent {
	std::string msg;
	char type_msg;
	public:
		ClientEvent();
		//ClientEvent(ClientEvent &&other);
		ModelEvent(ModelEvent&&) = default;
    	ModelEvent& operator = (ModelEvent&&) = default;

		char type();
		std::string to_string();

		~ClientEvent();

	private:
		ClientEvent(const ClientEvent &other) = delete;
		ClientEvent& operator=(const ClientEvent &other) = delete;
};

#endif