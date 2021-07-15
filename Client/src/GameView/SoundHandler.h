#ifndef SOUND_HANDLER_H
#define SOUND_HANDLER_H
#define KNIFE_RANGE 1
#define GLOCK_RANGE 5
#define AWP_RANGE 20
#define M3_RANGE 10
#define AK47_RANGE 10
#define BOMB_RANGE 50

class GameMap;

#include <vector>
#include <syslog.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include "Event.h"
#include "TypesOfEvents.h"
#include "ClientBomb.h"
#include "GameMap.h"

class SoundHandler {
	public:
		SoundHandler();
		void play(SoundEvent sound, float distance);
		void play(PositionType weapon, float distance);
		void handleAttack(Event& event, GameMap& map);
		void handleBomb(Event& event);
		void handleWalk();
		~SoundHandler();

	private:
		bool bomb_activated;
		Mix_Chunk* sound;
		Mix_Music* music;
		SoundHandler(const SoundHandler &other) = delete;
		SoundHandler& operator=(const SoundHandler &other) = delete;
};

#endif
