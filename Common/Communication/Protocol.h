#ifndef _PROTOCOL_H
#define _PROTOCOL_H

#include <string>
#include "Socket.h"
#include "Event.h"
#include "Exception.h"
#include "ExceptionInvalidCommand.h"
#include <memory>
#define LIST_CODE 0x6C
#define CREATE_CODE 0x6e
#define PLAY_CODE 0x70
#define JOIN_CODE 0x6a
#define ERROR_CODE 0xff
#define INVALID_NAME 0
#define INVALID_CODE 1


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
