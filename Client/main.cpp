#include <exception>
#include <syslog.h>

#include "Client.h"

int main(int argc, char *argv[]) {
	try {
		Client client;
		client.execute(argc, argv);
	} catch(std::exception& e) {
		syslog(LOG_CRIT, "[%s:%i]: %s", __FILE__, __LINE__, e.what());
	} catch(...) {
		syslog(LOG_CRIT, "[%s:%i]: Unknown error", __FILE__, __LINE__);
	}
	return 0;
}
