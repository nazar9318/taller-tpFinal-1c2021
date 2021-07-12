#ifndef SOUND_HANDLER_H
#define SOUND_HANDLER_H

#include <string>
#include <syslog.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include "Event.h"
#include "TypesOfEvents.h"

class SoundHandler {
	public:
		SoundHandler();
		static void play(SoundEvent sound);
		~SoundHandler();

	private:
		SoundHandler(const SoundHandler &other) = delete;
		SoundHandler& operator=(const SoundHandler &other) = delete;
};

#endif
