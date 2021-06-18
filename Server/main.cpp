#include <iostream>
#include <string>
#include <exception>
#include <syslog.h>

#include "Server.h"

#define ERROR 1
#define ARGC_EXPECTED 2

int main(int argc, char *argv[]) {
	std::string port("8080");
	if (argc != ARGC_EXPECTED) {
		syslog(LOG_CRIT, "[%s:%i]: Se enviaron %d argumentos"
				 " y se esperaban %d.", __FILE__, __LINE__,
				   argc, ARGC_EXPECTED);
	} else {
		port = argv[1];
	}
	try {
		Server server(port);
		server.excecute();
	} catch(std::exception& e) {
		syslog(LOG_CRIT, "[%s:%i]: %s", __FILE__, __LINE__, e.what());
	} catch(...) {
		syslog(LOG_CRIT, "[%s:%i]: Unknown error", __FILE__, __LINE__);
	}
	return 0;

	return 0;
}