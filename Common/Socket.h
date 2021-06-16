#ifndef _SOCKET_H
#define _SOCKET_H

#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>


#include "Exception.h"
#include "ExceptionSocketClosed.h"

#define CONNECTION_LOST -1
#define NOT_INITIALIZED -1

class Socket {
		int socket_fd;

	public:
		Socket(const std::string& host, const std::string& service);
		Socket();
		Socket(Socket &&other);

		// POST: Asocia al socket un file descriptor local para comunicarse 
		//       y lo conecta al IP(host) y Puerto(Servicio) especificado. 
		//       En caso de fallar, lanza la excepcion pertinente. 
		void connect_to(const std::string& host, const std::string& service);


		// PRE: No hay otro Socket asociado al servicio(puerto). 
		// POST: Une el socket con el puerto y le asigna un ID. 
		//       Crea una cola con size 5 para la espera a ser
		//       aceptados por el servidor. 
		//       En caso de fallar, lanza la excepcion pertinente. 
		void bind_listen(const std::string& service);		

		// POST: El socket que es servidor acepta una conexion desde el puerto.
		//       Retorna el Socket aceptado por el mismo. 
		//       En caso de fallar, lanza la excepcion pertinente. 
		Socket accept() const;

		// POST: Envia size bytes del buf a traves de la conexion de self.
		//       Retorna la cantidad de bytes enviados en caso de exito, 
		//       y la excepcion correspondiente en caso contrario. 
		unsigned send_message(const char* buf, const unsigned& size);

		// PRE: buf tiene suficiente espacio para almacenar size bytes. 
		// POST: Recibe size bytes y los guarda en el buf. 
		//		 Retorna la cantidad de bytes recibidos, o la excepcion
		//       correspondiente en caso de error. 
		unsigned recv_message(char* buf, const unsigned& size);

		void shutdown(int how = SHUT_RDWR);

		~Socket();

	private:
		explicit Socket(int file_descritor);
		Socket(const Socket &other) = delete;
		Socket& operator=(const Socket &other) = delete;
};

#endif

