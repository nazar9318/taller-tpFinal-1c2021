#ifndef _EXCEPTION_SOCKET_CLOSED_H
#define _EXCEPTION_SOCKET_CLOSED_H

#include <typeinfo>
#include <exception>

#define BUF_SIZE 256

class ExceptionSocketClosed: public Exception {
  	public:
		explicit ExceptionSocketClosed(const char* description)
    	:Exception("%s ", description) { }
		virtual ~ExceptionSocketClosed() noexcept {}
};

#endif
