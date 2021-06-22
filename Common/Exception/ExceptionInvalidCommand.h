#ifndef _EXCEPTION_INVALID_COMMAND_H
#define _EXCEPTION_INVALID_COMMAND_H

#include <exception>
#include "Exception.h"

class ExceptionInvalidCommand: public Exception {
	public:
		explicit ExceptionInvalidCommand(const char* description)
    	:Exception("%s ", description) { }
		virtual ~ExceptionInvalidCommand() noexcept {}
};

#endif
