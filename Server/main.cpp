#include <iostream>
#include <string>
#include <exception>
#include <syslog.h>
#include "Server.h"
#include "Configuration.h"

#define ERROR 1
#define ARGC_EXPECTED 2

int main(int argc, char *argv[]) {
	if (argc != ARGC_EXPECTED) {
		syslog(LOG_CRIT, "[%s:%i]: Se enviaron %d argumentos"
				 " y se esperaban %d.", __FILE__, __LINE__,
				   argc, ARGC_EXPECTED);
		//file_path_configs = "Server/src/Configuration/Configuration.yaml";
	} else {
		std::string file_path_configs(argv[1]);
		CF::load_configuration(file_path_configs);
	}
	try {
		Server server;
		server.execute();
	} catch(std::exception& e) {
		syslog(LOG_CRIT, "[%s:%i]: %s", __FILE__, __LINE__, e.what());
	} catch(...) {
		syslog(LOG_CRIT, "[%s:%i]: Unknown error", __FILE__, __LINE__);
	}
	return 0;
}