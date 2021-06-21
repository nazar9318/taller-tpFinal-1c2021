#ifndef _NOT_ENOUGH_PLAYERS_EXCEPTION_H
#define _NOT_ENOUGH_PLAYERS_EXCEPTION_H

#include <exception>
#include "Exception.h"

class NotEnoughPlayersException: public Exception {
	public:
		explicit NotEnoughPlayersException(const char* description)
    	:Exception("%s ", description) { }
		virtual ~NotEnoughPlayersException() noexcept {}
};

#endif
