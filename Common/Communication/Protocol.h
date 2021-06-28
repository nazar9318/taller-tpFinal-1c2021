#ifndef _PROTOCOL_H
#define _PROTOCOL_H

#include <vector>
#include <syslog.h>
#include <string>
#include <memory>

#include "Socket.h"
#include "Event.h"

class Protocol {
	public:
		Protocol();

		void send_event(Socket& socket, std::vector<char> msg);
		Event recv_event(Socket& socket);
		~Protocol();

	private:
		Protocol(const Protocol &other) = delete;
		Protocol& operator=(const Protocol &other) = delete;
};

#endif
