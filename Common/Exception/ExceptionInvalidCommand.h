#ifndef _EXCEPTION_INVALID_COMMAND_H
#define _EXCEPTION_INVALID_COMMAND_H

#include <exception>
#include "TypesOfEvents.h"
#include "Exception.h"

class ExceptionInvalidCommand: public Exception {
	ServerError command_error;
	public:
		ExceptionInvalidCommand(const char* description, 
			ServerError type_error): Exception("%s ",
										 description) { 
    		command_error = type_error;			
    	}
    	ServerError get_type() {
    		return command_error;
    	}

		virtual ~ExceptionInvalidCommand() noexcept {}
};

#endif
