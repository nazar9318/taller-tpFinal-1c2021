#include "Socket.h"
#include <stdlib.h>
#include <string.h>
#include <syslog.h>
#include <string>


// cito: Los metodos implementados en esta clase se basan
// en los archivos de ejemplo entregados por la catedra y los 
// ejemplos de la documentacion oficial de C y C++. Obviamente con 
// las pertinentes agregaciones y modificaciones para lograr
// lo buscado.  

#define SOCKET_ERROR -1
#define CONNECT_ERROR -1
#define QUEUE_LENGTH 5

Socket::Socket(): socket_fd(NOT_INITIALIZED) {
}


Socket::Socket(int file_descritor): socket_fd(file_descritor) {
}

Socket::Socket(Socket&& other) {
	this->socket_fd = other.socket_fd;
	other.socket_fd = NOT_INITIALIZED;
}

Socket::Socket(const std::string& host, const std::string& service): 
		socket_fd(NOT_INITIALIZED) {
	connect_to(host, service);
}




// POST: Asocia al socket un file descriptor local para comunicarse 
//       y lo conecta al IP(host) y Puerto(Servicio) especificado. 
//       En caso de fallar, lanza la excepcion pertinente. 
void Socket::connect_to(const std::string& hostname,
							 const std::string& service) {
	if (socket_fd != NOT_INITIALIZED) {
		throw Exception("[%s:%i]: No se puede hacer el connect de un socket" 
				" que ya esta asociado a un file descriptor. Se intenta hacer" 
				" el mismo con el host: %s y el service: %s", __FILE__,
				 __LINE__, hostname.c_str(), service.c_str());
	}

	struct addrinfo hints, *res;
	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_family = AF_INET; /* IPv4 */
	hints.ai_socktype = SOCK_STREAM; /* TCP*/
	hints.ai_flags = 0;
	int error_remote_address = getaddrinfo(hostname.c_str(), 
								service.c_str(), &hints, &res);
	if (error_remote_address) {
		throw Exception("[%s:%i]: Fallo la funcion getaddrinfo en" 
				" el connect con los parametros para el host: %s y" 
				" para el service: %s", __FILE__, __LINE__, 
				hostname.c_str(), service.c_str());
	}

	struct addrinfo* ptr = res;
	bool not_connected = true;
	int state;

	while (ptr && not_connected) {
		socket_fd = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
		if (socket_fd != SOCKET_ERROR) {
			state = connect(socket_fd, ptr->ai_addr, ptr->ai_addrlen);
			if (state == CONNECT_ERROR)
				close(socket_fd);
			else
				not_connected = false;
		}
		ptr = ptr->ai_next;	
  	}
	freeaddrinfo(res);
	if (not_connected) {
		socket_fd = NOT_INITIALIZED;
		throw Exception("[%s:%i]: No se pudo conectar el Socket para el connect"
				" con los parametros para el host: %s y  para el service: %s",
				__FILE__, __LINE__, hostname.c_str(), service.c_str());
	}
}


// PRE: No hay otro Socket asociado al servicio(puerto). 
// POST: Une el socket con el puerto y le asigna un ID. 
//       Crea una cola con tamanio 5 para la espera a ser
//       aceptados por el servidor. 
//       En caso de fallar, lanza la excepcion pertinente. 
void Socket::bind_listen(const std::string& service) {
	if (socket_fd != NOT_INITIALIZED)
		throw Exception("[%s:%i]: No se puede hacer el bind de un socket " 
				" que ya esta asociado a un file descriptor", __FILE__,
				 __LINE__);

	struct addrinfo hints, *res;
	int state;
	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_family = AF_INET; /* IPv4 */
	hints.ai_socktype = SOCK_STREAM; /* TCP*/
	hints.ai_flags = AI_PASSIVE;
	state = getaddrinfo(NULL, service.c_str(), &hints, &res);
	if (state != 0){
		throw Exception("[%s:%i]: Fallo la funcion getaddrinfo en" 
				" el metodo bind and listen con el parametro para el" 
				" service: %s ", __FILE__, __LINE__, service.c_str());
	}

	struct addrinfo* ptr = res;
	bool not_binded = true;
	int val = 1;

	while (ptr && not_binded) {
		socket_fd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
		if (socket_fd != SOCKET_ERROR) {
			state = setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
			if (state != -1) {
				state = bind(socket_fd, res->ai_addr, res->ai_addrlen);
				if (state != -1)
					not_binded = false;
			}
		}
		if (not_binded)
			close(socket_fd);
		ptr = ptr->ai_next;	
  	}
	freeaddrinfo(res);

	if (not_binded) {
		throw Exception("[%s:%i]: No se pudo crear un socket aceptador"
				" en bind and listen con el parametro para"
				" el service %s", __FILE__, __LINE__, service.c_str());
	}

	state = listen(socket_fd, QUEUE_LENGTH); 
	if (state == -1)
		throw Exception("[%s:%i]: No se pudo crear la cola "
				"en el listen para el service %s", 
				__FILE__, __LINE__, service.c_str());
}

// POST: El socket que es servidor acepta una conexion desde el puerto.
//       Retorna el Socket aceptado por el mismo. 
//       En caso de fallar, lanza la excepcion pertinente. 
Socket Socket::accept() const {
	int accept_fd = ::accept(socket_fd, NULL, NULL);
	if (accept_fd == -1)
		throw ExceptionSocketClosed("No se pudo conectar al cliente");
	Socket peer(accept_fd);
	return peer;
}

// POST: Envia size bytes del buf a traves de la conexion de self.
//       Retorna la cantidad de bytes enviados en caso de exito, 
//       y -1 en caso contrario. 
unsigned Socket::send_message(const char* buf, const unsigned& size) {
	unsigned sent = 0;
	bool is_the_socket_valid = true;
	while (sent < size && is_the_socket_valid) {
		int s = send(socket_fd, &buf[sent], size - sent, MSG_NOSIGNAL);
		if (s == 0 || s == -1)
			is_the_socket_valid = false;
		else 
			sent += s;
	}
	if (is_the_socket_valid)
		return sent;
	throw ExceptionSocketClosed("No se pudo enviar el mensaje");
}

// PRE: buf tiene suficiente espacio para almacenar size bytes. 
// POST: Recibe size bytes y los guarda en el buf. 
//		 Retorna la cantidad de bytes recibidos, o -1 en caso de error. 
unsigned Socket::recv_message(char* buf, const unsigned& size) {
	unsigned received = 0;
	bool is_the_socket_valid = true;
	while (received < size && is_the_socket_valid) {
		int s = recv(socket_fd, &buf[received], size - received, 0);
		if (s == 0 || s == -1)
			is_the_socket_valid = false;
		else 
			received += s;
	}
	if (is_the_socket_valid)
		return received;
	
	throw ExceptionSocketClosed("No se pudo recibir el mensaje");
}

void Socket::shutdown(int how) {
	if(socket_fd != SOCKET_ERROR)
		::shutdown(socket_fd, how);
}


Socket::~Socket() {
	if(socket_fd != SOCKET_ERROR) {
		::shutdown(socket_fd, SHUT_RDWR);
		close(socket_fd);
	}
}
