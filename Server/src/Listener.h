#ifndef _LISTENER_H
#define _LISTENER_H

#include <atomic>
#include "Thread.h"
#include "Socket.h"
#include "ExceptionSocketClosed.h"
#include "Home.h"
#include <string>

class Listener : public Thread {
	Socket accepter;
	Home home;
	std::atomic<bool> keep_running;
	
	public:
		explicit Listener(const std::string& port);

		// POST: Escucha y acepta clientes que intentan 
		//       conectarse al servidor. Estos son enviados al 
		//       home para que los maneje. 
		virtual void run() override;
		
		// POST: Fuerza la finalizacion del run al cortar la conexion. 
		void stop_conection();
		
		~Listener();

	private:
		Listener(const Listener &other) = delete;
		Listener& operator=(const Listener &other) = delete;
};


#endif
