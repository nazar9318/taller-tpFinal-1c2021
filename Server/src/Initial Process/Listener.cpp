#include "Listener.h"

#include <syslog.h>
#include <string>
#include <utility>

Listener::Listener(const std::string& port) {
	syslog(LOG_INFO, "Creando Listener con"
				" parametro %s", port.c_str());
	accepter.bind_listen(port);
	keep_running = true;
}


// POST: Escucha y acepta clientes que intentan 
//       conectarse al servidor. Estos son enviados al 
//       home para que los maneje. 
void Listener::run() {
	try {
		while (keep_running) {
			Socket client = accepter.accept();
			home.add_client(std::move(client));
		}
	} catch(ExceptionSocketClosed& e) {
		syslog(LOG_INFO, "[%s:%i]: Socket Closed", __FILE__, __LINE__);
	} catch(std::exception& e) {
		syslog(LOG_INFO, "[%s:%i] Se corto el run de Listener: %s.",
						 __FILE__, __LINE__, e.what());
	} catch(...) {
		syslog(LOG_CRIT, "[%s:%i]: Unknown error", __FILE__, __LINE__);
	}
}

// POST: Fuerza la finalizacion del run al cortar la conexion. 
void Listener::stop_conection() {
	accepter.shutdown();
	keep_running = false;
}

Listener::~Listener() {
	this->join();
}
