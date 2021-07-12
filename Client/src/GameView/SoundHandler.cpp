#include "SoundHandler.h"

SoundHandler::SoundHandler() {}

void SoundHandler::play(SoundEvent sound) {
	switch (sound) {
		case SoundEvent::AK47_SOUND : {
			Mix_Chunk* sound = Mix_LoadWAV("../Client/Assets/Sounds/ak47.wav");
			Mix_PlayChannel(-1, sound, 0);
			Mix_FreeChunk(sound);
			break;
		}
		case SoundEvent::AWP_SOUND : {
			Mix_Chunk* sound = Mix_LoadWAV("../Client/Assets/Sounds/awp.wav");
			Mix_PlayChannel(-1, sound, 0);
			Mix_FreeChunk(sound);
			break;
		}
		case SoundEvent::M3_SOUND : {
			Mix_Chunk* sound = Mix_LoadWAV("../Client/Assets/Sounds/m3.wav");
			Mix_PlayChannel(-1, sound, 0);
			Mix_FreeChunk(sound);
			break;
		}
		case SoundEvent::GLOCK_SOUND : {
			Mix_Chunk* sound = Mix_LoadWAV("../Client/Assets/Sounds/glock.wav");
			Mix_PlayChannel(-1, sound, 0);
			Mix_FreeChunk(sound);
			break;
		}
		case SoundEvent::KNIFE_SOUND : {
			Mix_Chunk* sound = Mix_LoadWAV("../Client/Assets/Sounds/knife.wav");
			Mix_PlayChannel(-1, sound, 0);
			Mix_FreeChunk(sound);
			break;
		}
		case SoundEvent::BOMB_PLACED_SOUND : {
			Mix_Chunk* sound = Mix_LoadWAV("../Client/Assets/Sounds/c4.wav");
			Mix_PlayChannel(-1, sound, 0);
			Mix_FreeChunk(sound);
			break;
		}
		case SoundEvent::BOMB_DEACTIVATED_SOUND : {
			Mix_Chunk* sound = Mix_LoadWAV("../Client/Assets/Sounds/c4_disarm.wav");
			Mix_PlayChannel(-1, sound, 0);
			Mix_FreeChunk(sound);
			break;
		}
		case SoundEvent::BOMB_EXPLODED_SOUND : {
			Mix_Chunk* sound = Mix_LoadWAV("../Client/Assets/Sounds/c4_explode.wav");
			Mix_PlayChannel(-1, sound, 0);
			Mix_FreeChunk(sound);
			break;
		}
		default:
			break;
	}
}

SoundHandler::~SoundHandler() {}
