#ifndef _EXCEPTION_MATCH_FULL_H
#define _EXCEPTION_MATCH_FULL_H

#include <exception>
#include "Exception.h"

class ExceptionMatchFull: public Exception {
	public:
		explicit ExceptionMatchFull(const char* description)
    	:Exception("%s ", description) { }
		virtual ~ExceptionMatchFull() noexcept {}
};

#endif
