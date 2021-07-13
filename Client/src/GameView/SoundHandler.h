#ifndef SOUND_HANDLER_H
#define SOUND_HANDLER_H

#include <vector>
#include <syslog.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include "Event.h"
#include "TypesOfEvents.h"
#include "ClientBomb.h"

class SoundHandler {
	public:
		SoundHandler();
		void play(SoundEvent sound);
		void play(PositionType weapon);
		void handle(Event& event);
		void handleBomb(Event& event);
		~SoundHandler();

	private:
		bool bomb_activated;
		Mix_Chunk* sound;
		std::vector<Mix_Chunk*> sounds;
		SoundHandler(const SoundHandler &other) = delete;
		SoundHandler& operator=(const SoundHandler &other) = delete;
};

#endif
