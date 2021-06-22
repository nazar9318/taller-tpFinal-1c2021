#ifndef SDL_EXCEPTION_H
#define SDL_EXCEPTION_H

#include "Exception.h"

class SDLException : public Exception {
    public:
      explicit SDLException(const char* fmt):Exception(fmt){}

      explicit SDLException(const char* fmt, const char* found):Exception(fmt, found){}

      explicit SDLException(const char* fmt, const char* file, int line):Exception(fmt, file, line){}

      ~SDLException() noexcept{}
};

#endif
