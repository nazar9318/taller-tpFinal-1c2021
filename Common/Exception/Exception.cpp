#include "Exception.h"

#include <string.h>
#include <errno.h>
#include <cstdarg>
#include <cstdio>

Exception::Exception(const char* format, ...) noexcept {
	int _errno = errno;

	va_list args;
	va_start(args, format);
	int msg_len = vsnprintf(error_msg, BUF_SIZE, format, args);
	va_end(args);

	strncpy(error_msg + msg_len, strerror(_errno), BUF_SIZE - msg_len);
	error_msg[BUF_SIZE - 1] = '\0';
}

const char* Exception::what() const noexcept {
	return error_msg; 
}

Exception::~Exception() {}
