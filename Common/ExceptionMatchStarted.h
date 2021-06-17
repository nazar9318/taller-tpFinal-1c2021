#ifndef _EXCEPTION_MATCH_STARTED_H
#define _EXCEPTION_MATCH_STARTED_H

#include <exception>
#include "Exception.h"

class ExceptionMatchStarted: public Exception {
	public:
		explicit ExceptionMatchStarted(const char* description)
    	:Exception("%s ", description) { }
		virtual ~ExceptionMatchStarted() noexcept {}
};

#endif
