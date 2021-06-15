#ifndef _PROTOCOL_H
#define _PROTOCOL_H

#include <string>
#include "Socket.h"


class Protocol {
	public:
		Protocol();
	
		~Protocol();

	private:
		Protocol(const Protocol &other) = delete;
		Protocol& operator=(const Protocol &other) = delete;
};

#endif
