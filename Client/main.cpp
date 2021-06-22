#include <string>
#include <exception>
#include <syslog.h>

#include "Client.h"

#define ERROR 1
#define ARGC_EXPECTED 3

int main(int argc, char *argv[]) {
	std::string host("localhost");
	std::string port("8080");
	if (argc != ARGC_EXPECTED) {
		syslog(LOG_CRIT, "[%s:%i]: Se enviaron %d argumentos"
						 " y se esperaban %d.", __FILE__, __LINE__,
						  argc, ARGC_EXPECTED);
	} else {
		host = argv[1];
		port = argv[2];
	}
	try {
		Client client(host, port);
		client.execute();
	} catch(std::exception& e) {
		syslog(LOG_CRIT, "[%s:%i]: %s", __FILE__, __LINE__, e.what());
	} catch(...) {
		syslog(LOG_CRIT, "[%s:%i]: Unknown error", __FILE__, __LINE__);
	}
	return 0;
}
