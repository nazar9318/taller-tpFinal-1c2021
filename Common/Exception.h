#ifndef _EXCEPTION_H
#define _EXCEPTION_H

#include <exception>

#define BUF_SIZE 256

class Exception: public std::exception {
		char error_msg[BUF_SIZE];
  
	public:
		Exception(const char* format, ...) noexcept;

		virtual const char* what() const noexcept;

		virtual ~Exception() noexcept;
};

#endif
