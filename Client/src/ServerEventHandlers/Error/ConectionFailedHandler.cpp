#include "ConectionFailedHandler.h"
#include <syslog.h>

ConectionFailedHandler::ConectionFailedHandler() {}

void ConectionFailedHandler::handle(Event& event, GameMap& map) {
	syslog(LOG_ERR, "[%s:%i]: Fallo la conexion"
					" cliente-servidor", __FILE__, __LINE__);
	throw Exception("Fallo la conexion cliente-servidor");
}

ConectionFailedHandler::~ConectionFailedHandler() {}
